using System;
using System.Collections.Generic;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace Calculator
{
    /// <summary>
    /// Логика взаимодействия для SettingsWindow.xaml
    /// </summary>
    internal partial class SettingsWindow : Window
    {
        public Settings Settings { get; set; }

        public SettingsWindow(Settings settings)
        {
            InitializeComponent();
            
            this.Settings = settings;
            InitUIAccordingToSettings();
        }

        private void InitUIAccordingToSettings()
        {
            rbOmitDenominator.IsChecked = Settings.OmitFractionDenominatorOfOne;
            rbOmitImPart.IsChecked = Settings.OmitComplexImPartOfZero;
            rbDisallowFractionalPNumbers.IsChecked = Settings.DisallowFractionalPNumbers;
        }

        private void FillSettingsFromUI()
        {
            Settings = new Settings
            {
                OmitFractionDenominatorOfOne = (bool)rbOmitDenominator.IsChecked,
                OmitComplexImPartOfZero = (bool)rbOmitImPart.IsChecked,
                DisallowFractionalPNumbers = (bool)rbDisallowFractionalPNumbers.IsChecked
            };
        }

        private void OnOKClick(object sender, RoutedEventArgs e)
        {
            FillSettingsFromUI();
            DialogResult = true;
            Close();
        }

        private void OnCancelClick(object sender, RoutedEventArgs e)
        {
            DialogResult = false;
            Close();
        }
    }
}
