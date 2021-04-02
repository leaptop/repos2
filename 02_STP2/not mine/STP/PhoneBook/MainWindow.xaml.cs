#nullable enable

using System;
using System.Linq;
using System.Windows;

namespace PhoneBook
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private const string RepositoryPath = "subscribers.dat";

        private SubscribersRepository repository;
        private SubscriberCollection subscribers;

        private string searchKey = "";

        public MainWindow()
        {
            InitializeComponent();

            repository = new SubscribersRepository(RepositoryPath);
            subscribers = repository.Read();

            UpdateItems();
        }

        private void UpdateItems()
        {
            subscribersLB.Items.Clear();
            foreach (var sub in subscribers)
            {
                if (sub.Name.Contains(searchKey, StringComparison.CurrentCultureIgnoreCase))
                {
                    subscribersLB.Items.Add(sub);
                }
            }
        }

        private void subscribersLB_SelectionChanged(object sender, System.Windows.Controls.SelectionChangedEventArgs e)
        {
            bool isSelected = subscribersLB.SelectedIndex != -1;
            editBtn.IsEnabled = isSelected;
            removeBtn.IsEnabled = isSelected;
        }

        private void addBtn_Click(object sender, RoutedEventArgs e)
        {
            var validator = new UniqueUsernameValidator(subscribers);
            var addWindow = AddEditWindow.CreateAddWindow(validator);
            if (addWindow.ShowDialog() == true)
            {
                subscribers.Add(addWindow.Subscriber);

                UpdateItems();
            }
        }
        
        private void editBtn_Click(object sender, RoutedEventArgs e)
        {
            var subscriber = (Subscriber)subscribersLB.SelectedItem;
            var validator = new UniqueUsernameValidator(subscribers, subscriber.Name);
            var editWindow = AddEditWindow.CreateEditWindow(subscriber, validator);
            if (editWindow.ShowDialog() == true)
            {
                subscribers.RemoveByName(subscriber.Name);

                var newSubscriber = editWindow.Subscriber;
                subscribers.Add(newSubscriber);

                UpdateItems();
            }
        }

        private void removeBtn_Click(object sender, RoutedEventArgs e)
        {
            var subscriber = (Subscriber)subscribersLB.SelectedItem;
            subscribers.RemoveByName(subscriber.Name);

            UpdateItems();
        }

        private void saveBtn_Click(object sender, RoutedEventArgs e)
        {
            repository.Write(subscribers);
        }

        private void searchTB_TextChanged(object sender, System.Windows.Controls.TextChangedEventArgs e)
        {
            searchKey = searchTB.Text;

            UpdateItems();
        }
    }
}
