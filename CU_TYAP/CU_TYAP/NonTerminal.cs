using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CU_TYAP
{
    public class NonTerminal
    {
        string S;
        char N;
        public char Symbol
        {
            get { return N; }
        }
        public List<string> replacements;
        public NonTerminal(char N)
        {
            S = "" + N;
            this.N = N;
            replacements = new List<string>();
        }
        public void AddReplacement(string Replacement)
        {
            if (!replacements.Contains(Replacement))
                replacements.Add(Replacement);
        }
        public string ToString()
        {
            string result = "";
            result += S;
            result += " → ";
            for (int i = 0; i < replacements.Count - 1; i++)
            {
                result += ((replacements[i] != "" ? replacements[i] : "\u03BB") + " | ");
            }
            result += (replacements[replacements.Count - 1] != "" ? replacements[replacements.Count - 1] : "\u03BB");
            return result;
        }
    }
}
