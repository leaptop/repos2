#nullable enable

using System;
using System.Collections.Generic;
using System.Text;

namespace PhoneBook
{
    public interface ISubscriberValidator
    {
        bool IsNameValid(string name, out string message);
        bool IsPhoneNumberValid(string name, out string message);
    }

    public class DefaultValidator : ISubscriberValidator
    {
        public virtual bool IsNameValid(string name, out string message)
        {
            if (name.Length == 0)
            {
                message = "Name is empty";
                return false;
            }
            message = "";
            return true;
        }

        public virtual bool IsPhoneNumberValid(string phoneNumber, out string message)
        {
            if (phoneNumber.Length == 0)
            {
                message = "Phone number is empty";
                return false;
            }
            message = "";
            return true;
        }
    }

    public class UniqueUsernameValidator : ISubscriberValidator
    {
        private DefaultValidator defaultValidator;
        private SubscriberCollection collection;
        private string? oldName;

        public UniqueUsernameValidator(SubscriberCollection collection, string? oldName = null)
        {
            this.defaultValidator = new DefaultValidator();

            this.collection = collection;
            this.oldName = oldName;
        }

        public bool IsNameValid(string name, out string message)
        {
            if (!defaultValidator.IsNameValid(name, out message))
            {
                return false;
            }
            if (name != oldName && collection.ContainsName(name))
            {
                message = $"Subscriber '{name}' already exists";
                return false;
            }
            return true;
        }

        public bool IsPhoneNumberValid(string name, out string message)
        {
            return defaultValidator.IsPhoneNumberValid(name, out message);
        }
    }
}
