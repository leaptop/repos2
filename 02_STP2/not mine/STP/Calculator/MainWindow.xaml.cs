using System;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using Editors;
using Numbers;
using Processor;

namespace Calculator
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private enum Mode { Fraction, Complex, PNumber }
        private Mode mode;

        private Button[] digitButtons;
        private UIElement[] fractionControls;
        private UIElement[] complexControls;
        private UIElement[] pnumberControls;

        private ICalculatorControl control;
        private History history = new History();

        private bool ComplexAuxPanelVisible => panelAuxComplex.IsVisible;
        private double ComplexAuxPanelWidth => panelAuxComplex.Width;
        private int ComplexAuxParam => (int)upDownComplexAuxParam.Value;
        private int PNumberBase => (int)upDownPNumBase.Value;


        public MainWindow()
        {
            InitializeComponent();

            InitDigitButtons();
            InitOperationButtons();
            InitPNumberBaseUpDown();
            InitModeSpecificControls();
            InitModeRadioButtons();
            SetMode(Mode.Fraction);
            UpdateUI();
        }

        private void InitDigitButtons()
        {
            digitButtons = new[]
            {
                button0, button1, button2, button3,
                button4, button5, button6, button7,
                button8, button9, buttonA, buttonB,
                buttonC, buttonD, buttonE, buttonF
            };

            for (int i = 0; i < digitButtons.Length; i++)
            {
                digitButtons[i].Tag = i;
                digitButtons[i].Click += OnDigitButtonClick;
            }
        }

        private void InitOperationButtons()
        {
            buttonAdd.Tag = BinaryOperation.Add;
            buttonSubtract.Tag = BinaryOperation.Subtract;
            buttonMultiplication.Tag = BinaryOperation.Multiply;
            buttonDivide.Tag = BinaryOperation.Divide;

            buttonInvert.Tag = UnaryOperation.Inverse;
            buttonSquare.Tag = UnaryOperation.Square;

            Button[] binary = { buttonAdd, buttonSubtract, buttonMultiplication, buttonDivide };
            foreach (var button in binary)
                button.Click += OnBinaryOperationClick;

            Button[] unary = { buttonInvert, buttonSquare };
            foreach (var button in unary)
                button.Click += OnUnaryOperationClick;
        }

        private void InitPNumberBaseUpDown()
        {
            upDownPNumBase.ValueChanged += OnPNumberBaseChanged;
        }

        private void InitModeSpecificControls()
        {
            fractionControls = new UIElement[]
            {
                buttonToggleSign, buttonSlash
            };
            complexControls = new UIElement[]
            {
                panelAuxComplex, buttonToggleSignRe,
                buttonToggleSignIm, buttonComplexComma,
                buttonComplexDelim
            };
            pnumberControls = new UIElement[]
            {
                buttonToggleSign, buttonPNumComma, gridPNumBase,
                buttonA, buttonB, buttonC,
                buttonD, buttonE, buttonF
            };
        }

        private void InitModeRadioButtons()
        {
            radioButtonFraction.Tag = Mode.Fraction;
            radioButtonComplex.Tag = Mode.Complex;
            radioButtonPNumber.Tag = Mode.PNumber;
            var radioButtons = new[] { radioButtonFraction, radioButtonComplex, radioButtonPNumber };
            foreach (var rb in radioButtons)
            {
                rb.Checked += (sender, e) => SetMode((Mode)((RadioButton)sender).Tag);
            }
        }

        private void SetControl(ICalculatorControl newControl)
        {
            if (this.control != null)
            {
                this.control.Error -= OnControlError;
            }
            this.control = newControl;
            newControl.Error += OnControlError;
        }

        private void SetMode(Mode mode)
        {
            this.mode = mode;

            Settings settings = control?.Settings ?? default;
            HideAllModeSpecificControls();
            switch (mode)
            {
                case Mode.Fraction:
                    ShowFractionControls();
                    SetControl(new CalculatorControl<Fraction>(new FractionEditor(), history, settings));
                    break;

                case Mode.Complex:
                    ShowComplexControls();
                    SetControl(new CalculatorControl<Complex>(new ComplexEditor(), history, settings));
                    break;

                case Mode.PNumber:
                    ShowPNumberControls();
                    SetControl(new CalculatorControl<PNumber>(new PNumberEditor(PNumberBase), history, settings));
                    break;
            }
            UpdateUI();
        }

        private void HideAllModeSpecificControls()
        {
            if (ComplexAuxPanelVisible)
            {
                this.Width -= ComplexAuxPanelWidth;
            }

            var all = fractionControls.Concat(complexControls).Concat(pnumberControls);
            foreach (var uiElement in all)
            {
                uiElement.Visibility = Visibility.Collapsed;
            }

            rowDefinitionABC.Height = new GridLength(0);
            rowDefinitionDEF.Height = new GridLength(0);
        }

        private void ShowFractionControls()
        {
            foreach (var uiElement in fractionControls)
            {
                uiElement.Visibility = Visibility.Visible;
            }
        }

        private void ShowComplexControls()
        {
            this.Width += ComplexAuxPanelWidth;

            foreach (var uiElement in complexControls)
            {
                uiElement.Visibility = Visibility.Visible;
            }
        }

        private void ShowPNumberControls()
        {
            foreach (var uiElement in pnumberControls)
            {
                uiElement.Visibility = Visibility.Visible;
            }

            rowDefinitionABC.Height = new GridLength(1, GridUnitType.Star);
            rowDefinitionDEF.Height = new GridLength(1, GridUnitType.Star);
        }

        private void UpdateUI()
        {
            UpdateDigitButtons();
            UpdateInputText();
            UpdateMemoryControls();
            UpdateComplexAuxControls();
            UpdatePNumberCommaButton();
        }

        private void UpdateDigitButtons()
        {
            for (int i = 0; i < digitButtons.Length; i++)
            {
                digitButtons[i].IsEnabled = (mode != Mode.PNumber || i < PNumberBase);
            }
        }

        private void UpdateInputText()
        {
            textBoxInput.Text = control.DisplayedInputText;
        }

        private void UpdateMemoryControls()
        {
            bool isOn = control.IsMemoryOn;
            buttonMemClear.IsEnabled = isOn;
            buttonMemRead.IsEnabled = isOn;
            textBlockMemIndicator.Visibility = isOn ? Visibility.Visible : Visibility.Collapsed;
        }

        private void UpdateComplexAuxControls()
        {
            textBoxComplexAux.Text = control.ComplexAuxText;
        }

        private void UpdatePNumberCommaButton()
        {
            buttonPNumComma.IsEnabled = !control.Settings.DisallowFractionalPNumbers;
        }

        private void CopyToClipboard()
        {
            control.CopyToClipboard();
        }

        private void PasteFromClipboard()
        {
            control.PasteFromClipboard();
            UpdateInputText();
        }

        private void OnControlError(Exception ex)
        {
            MessageBox.Show(ex.Message, "Error", MessageBoxButton.OK, MessageBoxImage.Warning);
            UpdateUI();
        }

        private void OnDigitButtonClick(object sender, RoutedEventArgs e)
        {
            int digit = (int)((Button)sender).Tag;
            control.AddDigit(digit);
            UpdateInputText();
        }

        private void OnMemClearClick(object sender, RoutedEventArgs e)
        {
            control.MemoryClear();
            UpdateMemoryControls();
        }

        private void OnMemReadClick(object sender, RoutedEventArgs e)
        {
            control.MemoryRead();
            UpdateMemoryControls();
            UpdateInputText();
        }

        private void OnMemAddClick(object sender, RoutedEventArgs e)
        {
            control.MemoryAdd();
            UpdateMemoryControls();
        }

        private void OnMemSaveClick(object sender, RoutedEventArgs e)
        {
            control.MemorySave();
            UpdateMemoryControls();
        }

        private void OnClearAllClick(object sender, RoutedEventArgs e)
        {
            control.ClearAll();
            UpdateUI();
        }

        private void OnClearInputClick(object sender, RoutedEventArgs e)
        {
            control.ClearInput();
            UpdateInputText();
        }

        private void OnBackspaceClick(object sender, RoutedEventArgs e)
        {
            control.Backspace();
            UpdateInputText();
        }

        private void OnBinaryOperationClick(object sender, RoutedEventArgs e)
        {
            var operation = (BinaryOperation)((Button)sender).Tag;
            control.BinaryOperation(operation);
            UpdateInputText();
        }

        private void OnUnaryOperationClick(object sender, RoutedEventArgs e)
        {
            var operation = (UnaryOperation)((Button)sender).Tag;
            control.UnaryOperation(operation);
            UpdateInputText();
        }

        private void OnToggleSignClick(object sender, RoutedEventArgs e)
        {
            control.ToggleSign();
            UpdateInputText();
        }

        private void OnToggleSignReClick(object sender, RoutedEventArgs e)
        {
            control.ToggleReSign();
            UpdateInputText();
        }

        private void OnToggleSignImClick(object sender, RoutedEventArgs e)
        {
            control.ToggleImSign();
            UpdateInputText();
        }

        private void OnFractionSlashClick(object sender, RoutedEventArgs e)
        {
            control.AddFractionSlash();
            UpdateInputText();
        }

        private void OnDecimalSeparatorClick(object sender, RoutedEventArgs e)
        {
            control.AddDecimalSeparator();
            UpdateInputText();
        }

        private void OnComplexImDelimClick(object sender, RoutedEventArgs e)
        {
            control.AddImDelimiter();
            UpdateInputText();
        }

        private void OnEqualsClick(object sender, RoutedEventArgs e)
        {
            control.ApplyOperation();
            UpdateInputText();
        }

        private void OnComplexPowClick(object sender, RoutedEventArgs e)
        {
            control.ApplyComplexPow(ComplexAuxParam);
            UpdateComplexAuxControls();
        }

        private void OnComplexRootClick(object sender, RoutedEventArgs e)
        {
            control.ApplyComplexRoot(ComplexAuxParam);
            UpdateComplexAuxControls();
        }

        private void OnComplexMagnitudeClick(object sender, RoutedEventArgs e)
        {
            control.ApplyComplexMagnitude();
            UpdateComplexAuxControls();
        }

        private void OnComplexArgDegClick(object sender, RoutedEventArgs e)
        {
            control.ApplyComplexArgDegrees();
            UpdateComplexAuxControls();
        }

        private void OnComplexArgRadClick(object sender, RoutedEventArgs e)
        {
            control.ApplyComplexArgRadians();
            UpdateComplexAuxControls();
        }

        private void OnPNumberBaseChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            control.ChangePNumberBase(PNumberBase);
            UpdateUI();
        }

        private void OnKeyDown(object sender, KeyEventArgs e)
        {
            if (upDownComplexAuxParam.IsKeyboardFocusWithin ||
                upDownPNumBase.IsKeyboardFocusWithin)
            {
                return;
            }

            Key key = e.Key;
            if (key >= Key.D0 && key <= Key.D9)
            {
                TryAddDigit(key - Key.D0);
            }
            else if (key >= Key.NumPad0 && key <= Key.NumPad9)
            {
                TryAddDigit(key - Key.NumPad0);
            }
            else if (key >= Key.A && key <= Key.F)
            {
                TryAddDigit(10 + key - Key.A);
            }
            else
            {
                switch (key)
                {
                    case Key.Back: control.Backspace(); break;
                    case Key.Delete: control.ClearInput(); break;
                    case Key.Return: control.ApplyOperation(); break;
                    case Key.OemComma:
                    case Key.OemPeriod:
                        control.AddDecimalSeparator();
                        break;
                    case Key.Add:
                    case Key.OemPlus:
                        control.BinaryOperation(BinaryOperation.Add); 
                        break;
                    case Key.Subtract:
                    case Key.OemMinus: 
                        control.BinaryOperation(BinaryOperation.Subtract); 
                        break;
                    case Key.Multiply: 
                        control.BinaryOperation(BinaryOperation.Multiply); 
                        break;
                    case Key.Oem2:
                    case Key.Divide: 
                        control.BinaryOperation(BinaryOperation.Divide); 
                        break;
                    case Key.OemBackslash:
                    case Key.Oem5: 
                        control.AddFractionSlash(); 
                        break;
                }
            }
            UpdateUI();

            void TryAddDigit(int digit)
            {
                if ((mode == Mode.PNumber && digit < PNumberBase) ||
                    (mode != Mode.PNumber && digit < 10))
                {
                    control.AddDigit(digit);
                }
            }
        }

        private void OnCopyClick(object sender, RoutedEventArgs e)
        {
            CopyToClipboard();
        }

        private void OnPasteClick(object sender, RoutedEventArgs e)
        {
            PasteFromClipboard();
        }

        private void OnHistoryClick(object sender, RoutedEventArgs e)
        {
            new HistoryWindow(history).ShowDialog();
        }

        private void OnSettingsClick(object sender, RoutedEventArgs e)
        {
            var settingsWindow = new SettingsWindow(control.Settings);
            if (settingsWindow.ShowDialog() == true)
            {
                control.Settings = settingsWindow.Settings;
                UpdateUI();
            }
        }

        private void OnHelpClick(object sender, RoutedEventArgs e)
        {
            new HelpWindow().ShowDialog();
        }
    }
}
