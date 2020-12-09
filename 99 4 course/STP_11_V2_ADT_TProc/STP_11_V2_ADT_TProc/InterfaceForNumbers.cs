using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STP_11_ADT_TProc
{
   public interface InterfaceForNumbers<T> where T : new()
    {
        T add(T a, T b);
        T mul(T a, T b);
        T sub(T a, T b);
        T dvd(T a, T b);
        T none(T a, T b);
        T rev(T a);
        T sqr(T a);
    }
}
