using System;
using System.Windows;
using Editors;
using Lab1;
using Numbers;
using Processor;

namespace Calculator
{
    enum CalculatorState
    {
        StartEditing, BinaryOperationSet,
        SecondOperandEditing, BinaryOperationApplied
    }

    interface ICalculatorControl
    {
        event Action<Exception> Error;

        Settings Settings { get; set; }
        string DisplayedInputText { get; }
        bool IsMemoryOn { get; }
        string ComplexAuxText { get; }

        void ChangePNumberBase(int newBase);
        void AddDigit(int digit);
        void Backspace();
        void ToggleSign();
        void ToggleReSign();
        void ToggleImSign();
        void AddDecimalSeparator();
        void AddFractionSlash();
        void AddImDelimiter();
        void ClearInput();
        void ClearAll();
        void BinaryOperation(BinaryOperation operation);
        void UnaryOperation(UnaryOperation operation);
        void ApplyOperation();
        void MemoryClear();
        void MemoryRead();
        void MemorySave();
        void MemoryAdd();
        void ApplyComplexPow(int y);
        void ApplyComplexRoot(int y);
        void ApplyComplexMagnitude();
        void ApplyComplexArgDegrees();
        void ApplyComplexArgRadians();
        void CopyToClipboard();
        void PasteFromClipboard();
    }

    class CalculatorControl<TNumber> : ICalculatorControl
        where TNumber : INumber<TNumber>, new()
    {
        private static readonly string ClipboardFormatPrefix = "CalcInputNumber";

        private CalculatorState state;
        private IEditor<TNumber> editor;
        private Processor<TNumber> processor;
        private Memory.Memory<TNumber> memory;
        private History history;

        public event Action<Exception> Error;

        public Settings Settings { get; set; }
        public string DisplayedInputText => editor.Value;
        public bool IsMemoryOn => memory.State == Memory.MemoryState.On;
        public string ComplexAuxText { get; private set; } = "";

        private TNumber EditorValueAsNumber
        {
            get => editor.ValueAsNumber;
            set => editor.Value = value.ToStringFormatted(Settings);
        }

        public CalculatorControl(IEditor<TNumber> editor, History history, Settings settings)
        {
            state = CalculatorState.StartEditing;
            processor = new Processor<TNumber>();
            memory = new Memory.Memory<TNumber>();

            this.editor = editor ?? throw new ArgumentNullException();
            this.history = history ?? throw new ArgumentNullException();

            this.Settings = settings;
        }

        public void ChangePNumberBase(int newBase)
        {
            Try(() =>
            {
                if (this.editor is PNumberEditor { ValueAsNumber: PNumber currValue })
                {
                    PNumber newValue = PNumberConverter.ToAnotherBase(currValue, newBase);

                    var newEditor = new PNumberEditor(newBase);
                    newEditor.ValueAsNumber = newValue;
                    this.editor = newEditor as IEditor<TNumber>;

                    memory = new Memory.Memory<TNumber>();

                    processor.ResetAll();
                    memory.Clear();
                    state = CalculatorState.StartEditing;
                }
            });
        }

        public void AddDigit(int digit)
        {
            Try(() =>
            {
                switch (state)
                {
                    case CalculatorState.StartEditing:
                    case CalculatorState.SecondOperandEditing:
                        editor.AddDigit(digit);
                        break;

                    case CalculatorState.BinaryOperationSet:
                        editor.Clear();
                        editor.AddDigit(digit);
                        state = CalculatorState.SecondOperandEditing;
                        break;

                    case CalculatorState.BinaryOperationApplied:
                        editor.Clear();
                        editor.AddDigit(digit);
                        state = CalculatorState.StartEditing;
                        break;
                }
            });
        }

        public void Backspace()
        {
            Try(() =>
            {
                switch (state)
                {
                    case CalculatorState.StartEditing:
                    case CalculatorState.SecondOperandEditing:
                        editor.Backspace();
                        break;
                    
                    case CalculatorState.BinaryOperationSet:
                        editor.Clear();
                        state = CalculatorState.SecondOperandEditing;
                        break;

                    case CalculatorState.BinaryOperationApplied:
                        editor.Clear();
                        state = CalculatorState.StartEditing;
                        break;
                }
            });
        }

        public void ToggleSign()
        {
            Try(() =>
            {
                ClearEditorIfWasBinaryOperation();
                switch (editor)
                {
                    case FractionEditor fe: fe.ToggleSign(); break;
                    case PNumberEditor pe: pe.ToggleSign(); break;
                }
                UpdateStateDueToInput();
            });
        }

        public void ToggleReSign()
        {
            Try(() =>
            {
                ClearEditorIfWasBinaryOperation();
                (editor as ComplexEditor)?.ToggleReSign();
                UpdateStateDueToInput();
            });
        }

        public void ToggleImSign()
        {
            Try(() =>
            {
                ClearEditorIfWasBinaryOperation();
                (editor as ComplexEditor)?.ToggleImSign();
                UpdateStateDueToInput();
            });
        }

        public void AddDecimalSeparator()
        {
            Try(() =>
            {
                ClearEditorIfWasBinaryOperation();
                switch (editor)
                {
                    case PNumberEditor pe: pe.AddDecimalSeparator(); break;
                    case ComplexEditor ce: ce.AddDecimalSeparator(); break;
                }
                UpdateStateDueToInput();
            });
        }

        public void AddFractionSlash()
        {
            Try(() =>
            {
                ClearEditorIfWasBinaryOperation();
                (editor as FractionEditor)?.AddSlash();
                UpdateStateDueToInput();
            });
        }

        public void AddImDelimiter()
        {
            Try(() =>
            {
                ClearEditorIfWasBinaryOperation();
                (editor as ComplexEditor)?.AddImDelimiter();
                UpdateStateDueToInput();
            });
        }

        public void ClearInput()
        {
            Try(() =>
            {
                editor.Clear();
            });
        }

        public void ClearAll()
        {
            Try(() =>
            {
                state = CalculatorState.StartEditing;
                processor.ResetAll();
                editor.Clear();
                memory.Clear();
            });
        }

        public void BinaryOperation(BinaryOperation operation)
        {
            Try(() =>
            {
                switch (state)
                {
                    case CalculatorState.StartEditing:
                    case CalculatorState.BinaryOperationApplied:
                        processor.LeftOperand = EditorValueAsNumber;
                        processor.BinaryOperation = operation;
                        state = CalculatorState.BinaryOperationSet;
                        break;

                    case CalculatorState.BinaryOperationSet:
                        processor.BinaryOperation = operation;
                        break;

                    case CalculatorState.SecondOperandEditing:
                        processor.RightOperand = EditorValueAsNumber;
                        ApplyBinaryOperationAndRecord();
                        EditorValueAsNumber = processor.LeftOperand;
                        processor.BinaryOperation = operation;
                        state = CalculatorState.BinaryOperationSet;
                        break;
                }
            });
        }

        public void UnaryOperation(UnaryOperation operation)
        {
            Try(() =>
            {
                processor.RightOperand = EditorValueAsNumber;
                ApplyUnaryOperationAndRecord(operation);
                EditorValueAsNumber = processor.RightOperand;

                UpdateStateDueToInput();
            });
        }

        public void ApplyOperation()
        {
            Try(() =>
            {
                if (state != CalculatorState.StartEditing)
                {
                    if (state != CalculatorState.BinaryOperationApplied)
                    {
                        processor.RightOperand = EditorValueAsNumber;
                    }
                    ApplyBinaryOperationAndRecord();
                    EditorValueAsNumber = processor.LeftOperand;
                    state = CalculatorState.BinaryOperationApplied;
                }
            });
        }

        public void MemoryClear()
        {
            Try(() =>
            {
                memory.Clear();
            });
        }

        public void MemoryRead()
        {
            Try(() =>
            {
                EditorValueAsNumber = memory.Number;
            });
        }

        public void MemorySave()
        {
            Try(() =>
            {
                memory.Number = EditorValueAsNumber;
            });
        }

        public void MemoryAdd()
        {
            Try(() =>
            {
                memory.Add(EditorValueAsNumber);
            });
        }

        public void ApplyComplexPow(int y)
        {
            Try(() =>
            {
                if (EditorValueAsNumber is Complex x)
                    ComplexAuxText = x.Pow(y).ToString();
            });
        }

        public void ApplyComplexRoot(int y)
        {
            Try(() =>
            {
                if (EditorValueAsNumber is Complex x)
                    ComplexAuxText = string.Join(";\n", x.AllRoots(y));
            });
        }

        public void ApplyComplexMagnitude()
        {
            Try(() =>
            {
                if (EditorValueAsNumber is Complex x)
                    ComplexAuxText = x.Magnitude.ToString();
            });
        }

        public void ApplyComplexArgDegrees()
        {
            Try(() =>
            {
                const double rad2deg = 180 / Math.PI;
                if (EditorValueAsNumber is Complex x)
                    ComplexAuxText = (x.Phase * rad2deg).ToString();
            });
        }

        public void ApplyComplexArgRadians()
        {
            Try(() =>
            {
                if (EditorValueAsNumber is Complex x)
                    ComplexAuxText = (x.Phase).ToString();
            });
        }

        private void Try(Action action)
        {
            try
            {
                action();
            }
            catch (Exception ex)
            {
                ClearAll();
                Error?.Invoke(ex);
            }
        }

        private void ClearEditorIfWasBinaryOperation()
        {
            if (state == CalculatorState.BinaryOperationSet ||
                state == CalculatorState.BinaryOperationApplied)
            {
                editor.Clear();
            }
        }

        private void ApplyBinaryOperationAndRecord()
        {
            var record = new BinaryOperationRecord<TNumber>
            {
                Left = processor.LeftOperand,
                Right = processor.RightOperand,
                Operation = processor.BinaryOperation
            };
            
            processor.ApplyBinaryOperation();
            
            record.Result = processor.LeftOperand;
            history.AddRecord(record);
        }

        private void ApplyUnaryOperationAndRecord(UnaryOperation operation)
        {
            var record = new UnaryOperationRecord<TNumber>
            {
                Input = processor.RightOperand,
                Operation = operation
            };

            processor.ApplyUnaryOperationToRightOperand(operation);

            record.Result = processor.RightOperand;
            history.AddRecord(record);
        }

        private void UpdateStateDueToInput()
        {
            switch (state)
            {
                case CalculatorState.BinaryOperationSet:
                    state = CalculatorState.SecondOperandEditing;
                    break;
                case CalculatorState.BinaryOperationApplied:
                    state = CalculatorState.StartEditing;
                    break;
            }
        }

        public void CopyToClipboard()
        {
            Clipboard.SetData(GetClipboardFormat(), EditorValueAsNumber);
        }

        public void PasteFromClipboard()
        {
            string format = GetClipboardFormat();
            if (Clipboard.ContainsData(format))
            {
                EditorValueAsNumber = (TNumber)Clipboard.GetData(format);
            }
        }

        private string GetClipboardFormat()
        {
            string format = ClipboardFormatPrefix + typeof(TNumber).Name;
            if (EditorValueAsNumber is PNumber { Base: var @base })
            {
                format += @base;
            }
            return format;
        }
    }
}
