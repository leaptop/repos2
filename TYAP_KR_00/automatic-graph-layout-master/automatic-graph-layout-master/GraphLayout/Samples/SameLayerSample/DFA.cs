/*using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System;
using SCG = System.Collections.Generic;
using C5;

using state = System.Int32;
using input = System.Char;
namespace CourseWorkDFA {
    class DFA {

        /// <summary>
        /// Implements a deterministic finite automata (DFA)
        /// </summary>

        // Start state
        public state start;
        // Set of final states
        public Set<state> final;
        // Transition table
        public SCG.SortedList<KeyValuePair<state, input>, state> transTable;

        public DFA() {
            final = new Set<state>();

            transTable = new SCG.SortedList<KeyValuePair<state, input>, state>(new Comparer());
        }

        public string Simulate(string @in) {
            state curState = start;

            CharEnumerator i = @in.GetEnumerator();

            while (i.MoveNext()) {
                KeyValuePair<state, input> transition = new KeyValuePair<state, input>(curState, i.Current);

                if (!transTable.ContainsKey(transition))
                    return "Rejected";

                curState = transTable[transition];
            }

            if (final.Contains(curState))
                return "Accepted";
            else
                return "Rejected";
        }

        public void Show() {
            Console.Write("DFA start state: {0}\n", start);
            Console.Write("DFA final state(s): ");

            SCG.IEnumerator<state> iE = final.GetEnumerator();

            while (iE.MoveNext())
                Console.Write(iE.Current + " ");

            Console.Write("\n\n");

            foreach (SCG.KeyValuePair<KeyValuePair<state, input>, state> kvp in transTable)
                Console.Write("Trans[{0}, {1}] = {2}\n", kvp.Key.Key, kvp.Key.Value, kvp.Value);
        }
    }

    /// <summary>
    /// Implements a comparer that suits the transTable SordedList
    /// </summary>
    public class Comparer : SCG.IComparer<KeyValuePair<state, input>> {
        public int Compare(KeyValuePair<state, input> transition1, KeyValuePair<state, input> transition2) {
            if (transition1.Key == transition2.Key)
                return transition1.Value.CompareTo(transition2.Value);
            else
                return transition1.Key.CompareTo(transition2.Key);
        }
    }

}
//As you see, a DFA has 3 variables: a start state, a set of final states and a transition table that maps transitions between states.

   // Below I present the SubsetMachine class that is responsible for the hard work of extracting an equivalent DFA from a given NFA:

//
//  Regular Expression Engine C# Sample Application
//  2006, by Leniel Braz de Oliveira Macaferi & Wellington Magalhães Leite.
//
//  UBM's Computer Engineering - 7th term [http://www.ubm.br/]
//  
//  This program sample was developed and turned in as a term paper for Lab. of
//  Compilers Construction. It was based on the source code provided by Eli Bendersky
//  [http://eli.thegreenplace.net/] and is provided "as is" without warranty.
//

                                                                                                                      
}
*/