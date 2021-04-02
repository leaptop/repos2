using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace Lab1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private ConverterControl control;
        private Button[] digitButtons;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            inputBaseSlider.ValueChanged += inputBaseSlider_ValueChanged;
            outputBaseSlider.ValueChanged += outputBaseSlider_ValueChanged;

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
                digitButtons[i].Click += digitButton_Click;
            }

            control = new ConverterControl(10, 16);
            UpdateUI();
        }

        private void digitButton_Click(object sender, RoutedEventArgs e)
        {
            int digit = (int)((Button)sender).Tag;
            control.AddDigit(digit);
            UpdateUI();
        }

        private void inputBaseSlider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            control.InputBase = (int)inputBaseSlider.Value;
            UpdateUI();
        }

        private void outputBaseSlider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            control.OutputBase = (int)outputBaseSlider.Value;
            UpdateUI();
        }

        private void buttonSeparator_Click(object sender, RoutedEventArgs e)
        {
            control.AddDecimalSeparator();
            UpdateUI();
        }

        private void buttonBackspace_Click(object sender, RoutedEventArgs e)
        {
            control.Backspace();
            UpdateUI();
        }

        private void buttonClear_Click(object sender, RoutedEventArgs e)
        {
            control.Clear();
            UpdateUI();
        }

        private void buttonExecute_Click(object sender, RoutedEventArgs e)
        {
            control.PerformConversion();
            UpdateUI();
        }

        private void Window_KeyDown(object sender, KeyEventArgs e)
        {
            char keyChar = (char)KeyInterop.VirtualKeyFromKey(e.Key);
            if (keyChar >= '0' && keyChar <= '9')
            {
                TryAddDigit(keyChar - '0');
            }
            else if (keyChar >= 'A' && keyChar <= 'F')
            {
                TryAddDigit(10 + keyChar - 'A');
            }
            else
            {
                switch (e.Key)
                {
                    case Key.Back:
                        control.Backspace();
                        break;
                    case Key.Delete:
                        control.Clear();
                        break;
                    case Key.Return:
                        control.PerformConversion();
                        break;
                    case Key.OemComma:
                    case Key.OemPeriod:
                        control.AddDecimalSeparator();
                        break;
                }
            }
            UpdateUI();


            void TryAddDigit(int digit)
            {
                if (digit < control.InputBase)
                    control.AddDigit(digit);
            }
        }

        private void historyItem_Click(object sender, RoutedEventArgs e)
        {
            new HistoryWindow(control.History).Show();
        }

        private void helpItem_Click(object sender, RoutedEventArgs e)
        {
            new AboutWindow().Show();
        }

        private void UpdateUI()
        {
            inputBaseSlider.Value = control.InputBase;
            inputBaseLabel.Text = $"Input base: {control.InputBase}";

            outputBaseSlider.Value = control.OutputBase;
            outputBaseLabel.Text = $"Output base: {control.OutputBase}";

            inputTB.Text = control.DisplayedInput;
            outputTB.Text = control.DisplayedOutput;

            for (int i = 0; i < control.InputBase; i++)
            {
                digitButtons[i].IsEnabled = true;
            }
            for (int i = control.InputBase; i < digitButtons.Length; i++)
            {
                digitButtons[i].IsEnabled = false;
            }
        }
    }
}
