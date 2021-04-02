using System;
using System.Collections.Generic;
using System.Text;
using Editors;
using Numbers;

namespace Lab1
{
    class ConverterControl
    {
        private enum State { Editing, Converted }
        
        private State state;
        private int inputBase;
        private int outputBase;
        private PNumberEditor editor;
        private PNumber output = new PNumber();

        public string DisplayedInput => editor.Value;

        public string DisplayedOutput => output.ToString();

        public int InputBase
        {
            get => inputBase;
            set
            {
                PNumber.AssertValidBase(value);

                inputBase = value;

                PNumber newInput = PNumberConverter.ToAnotherBase(editor.ValueAsNumber, inputBase);
                editor = new PNumberEditor(inputBase);
                editor.ValueAsNumber = newInput;
            }
        }

        public int OutputBase
        {
            get => outputBase;
            set
            {
                PNumber.AssertValidBase(value);

                outputBase = value;

                output = PNumberConverter.ToAnotherBase(output, value);
            }
        }
        
        public History History { get; private set; }


        public ConverterControl(int initialInputBase, int initialOutputBase)
        {
            PNumber.AssertValidBase(initialInputBase);
            PNumber.AssertValidBase(initialOutputBase);

            inputBase = initialInputBase;
            outputBase = initialOutputBase;

            editor = new PNumberEditor(inputBase);
            History = new History();

            ClearDisplayedOutput();
        }

        public void AddDigit(int digit)
        {
            PreEdit();
            editor.AddDigit(digit);
        }

        public void AddDecimalSeparator()
        {
            PreEdit();
            editor.AddDecimalSeparator();
        }

        public void Backspace()
        {
            PreEdit();
            editor.Backspace();
        }

        public void Clear()
        {
            state = State.Editing;
            editor.Clear();
            ClearDisplayedOutput();
        }

        public void PerformConversion()
        {
            state = State.Converted;

            PNumber input = editor.ValueAsNumber;
            output = PNumberConverter.ToAnotherBase(input, OutputBase);

            History.AddRecord(new HistoryRecord(input, output));
        }


        private void ClearDisplayedOutput()
        {
            output = new PNumber();
        }

        private void PreEdit()
        {
            if (state == State.Converted)
            {
                Clear();
            }
        }
    }
}
