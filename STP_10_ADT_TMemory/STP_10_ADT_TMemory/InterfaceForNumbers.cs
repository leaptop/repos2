using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STP_10_ADT_TMemory
{
    public interface InterfaceForNumbers<T> where T : new()
    {
        T add(T other);
    }
}
