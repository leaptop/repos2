#nullable enable

using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace PhoneBook
{
    /// <summary>
    /// Логика взаимодействия для AddEditWindow.xaml
    /// </summary>
    public partial class AddEditWindow : Window
    {
        private static readonly Brush ErrorBrush = new SolidColorBrush(
            Color.FromArgb(255, 255, 205, 205));

        private bool nameIsOk = true;
        private bool phoneNumbersAreOk = true;

        public Subscriber Subscriber { 
            get
            {
                var subscriber = new Subscriber(nameTB.Text);
                foreach (var tb in phoneNumbersLB.Items.OfType<TextBox>())
                {
                    subscriber.PhoneNumbers.Add(tb.Text);
                }
                return subscriber;
            }
        }

        public ISubscriberValidator Validator { get; set; }

        public AddEditWindow()
        {
            InitializeComponent();

            Validator = new DefaultValidator();
            nameTB.TextChanged += (s, e) => ValidateName();
            phoneNumbersLB.SelectionChanged += (s, e) =>
            {
                removeBtn.IsEnabled = phoneNumbersLB.SelectedIndex != -1;
            };
        }

        public static AddEditWindow CreateAddWindow(ISubscriberValidator validator)
        {
            return new AddEditWindow
            {
                Validator = validator
            };
        }

        public static AddEditWindow CreateEditWindow(Subscriber subscriber, 
            ISubscriberValidator validator)
        {
            var window = new AddEditWindow
            {
                Validator = validator
            };
            window.PopulateWithSubscriberData(subscriber);
            return window;
        }

        private void PopulateWithSubscriberData(Subscriber subscriber)
        {
            nameTB.Text = subscriber.Name;

            foreach (var phoneNumber in subscriber.PhoneNumbers)
            {
                AddPhoneNumberTextBox(phoneNumber);
            }

            ValidateAll();
        }

        private void AddPhoneNumberTextBox(string phoneNumber = "")
        {
            var textBox = new TextBox
            {
                Text = phoneNumber
            };
            textBox.GotFocus += OnPhoneNumberTextBoxGotFocus;
            textBox.TextChanged += OnPhoneNumberTextBoxTextChanged;
            phoneNumbersLB.Items.Add(textBox);
            ValidatePhoneNumbers();
        }

        private void OnPhoneNumberTextBoxGotFocus(object sender, RoutedEventArgs e)
        {
            phoneNumbersLB.SelectedItem = sender;
        }

        private void RemovePhoneNumberTextBox(TextBox textBox)
        {
            textBox.GotFocus -= OnPhoneNumberTextBoxGotFocus;
            textBox.TextChanged -= OnPhoneNumberTextBoxTextChanged;
            phoneNumbersLB.Items.Remove(textBox);
            ValidatePhoneNumbers();
        }

        private void OnPhoneNumberTextBoxTextChanged(object sender, TextChangedEventArgs e)
        {
            ValidatePhoneNumbers();
        }

        private void ValidateAll()
        {
            ValidateName();
        }

        private void ValidateName()
        {
            if (!Validator.IsNameValid(nameTB.Text, out string message))
            {
                nameTB.Background = ErrorBrush;
                nameErrorTB.Text = message;
                nameErrorTB.Visibility = Visibility.Visible;
                nameIsOk = false;
            }
            else
            {
                nameTB.Background = Brushes.White;
                nameErrorTB.Visibility = Visibility.Hidden;
                nameIsOk = true;
            }

            UpdateOkButtonEnability();
        }

        private void ValidatePhoneNumbers()
        {
            phoneNumbersAreOk = true;
            
            foreach (var tb in phoneNumbersLB.Items.OfType<TextBox>())
            {
                tb.Background = Brushes.White;
            }

            foreach (var tb in phoneNumbersLB.Items.OfType<TextBox>())
            {
                if (!Validator.IsPhoneNumberValid(tb.Text, out string message))
                {
                    phoneNumbersErrorTB.Text = message;
                    tb.Background = ErrorBrush;
                    phoneNumbersAreOk = false;
                    break;
                }
            }
            phoneNumbersErrorTB.Visibility = phoneNumbersAreOk 
                    ? Visibility.Hidden 
                    : Visibility.Visible;

            UpdateOkButtonEnability();
        }

        private void UpdateOkButtonEnability()
        {
            okBtn.IsEnabled = nameIsOk && phoneNumbersAreOk;
        }

        private void addBtn_Click(object sender, RoutedEventArgs e)
        {
            AddPhoneNumberTextBox();
        }

        private void removeBtn_Click(object sender, RoutedEventArgs e)
        {
            RemovePhoneNumberTextBox((TextBox)phoneNumbersLB.SelectedItem);
        }

        private void okBtn_Click(object sender, RoutedEventArgs e)
        {
            DialogResult = true;
            Close();
        }

        private void cancelBtn_Click(object sender, RoutedEventArgs e)
        {
            DialogResult = false;
            Close();
        }
    }
}
