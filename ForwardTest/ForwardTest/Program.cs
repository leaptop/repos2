using System;

namespace ForwardTest
{
    class CurrentCoeffs
    {
        public double secondFrom = 0;//start of current period of time
        public double secondsDelta = 0; //time of activity
        public double secondTo = 0;//end of current period of time
        public double Vh;//speed of heating
        public double Vc;//speed of cooling
        public double M;//torque
        public double V;//speed of rotation of crankshaft(коленвал)
        public double a;//acceleration (speed of changing of speed of crankshaft)
    }
    class Program
    {
        static double I = 10;
        static double[] M = { 20, 75, 100, 105, 75, 0 };
        static double[] V = { 0, 75, 150, 200, 250, 300 };
        static double T_overheat = 110;
        static double Hm = 0.01;
        static double Hv = 0.0001;
        static double C = 0.01;

        static double T_outside = 20;//"normal" conditions
        static double T_engine = 20;
        static double deltaSpeed;//speed(V) change to achieve the next torque(M)
        static CurrentCoeffs[] ccf;
        static double time;

        static void testEngineByT_outside(double temp)
        {
            T_engine = T_outside = temp;
            int i = 0;
            ccf = new CurrentCoeffs[M.Length];
            for (; i < M.Length; i++)
            {
                ccf[i] = new CurrentCoeffs();
                ccf[i].M = M[i];
                ccf[i].V = V[i];
                ccf[i].Vh = ccf[i].M * Hm + ccf[i].V * ccf[i].V * Hv;//the engine heats up by this formula(Celcius degrees per second)
                //ccf[i].Vc = C * (T_outside - T_engine);//the engine cools down by this formula(Celcius degrees per second). It's commented because it's used in other part of this program
                ccf[i].a = ccf[i].M / I;
                if (i != 0)
                {
                    ccf[i].secondFrom = ccf[i - 1].secondTo;//start of usage of current coefficients is at the end of previous period of time
                }
                if (i != M.Length - 1)
                {
                    deltaSpeed = V[i + 1] - V[i];
                    ccf[i].secondsDelta = deltaSpeed / ccf[i].a;
                    ccf[i].secondTo = ccf[i].secondFrom + ccf[i].secondsDelta;
                }
                else
                {//what's below is not needed apparently...
                    ccf[i].secondTo = Double.MaxValue;//now there are no limits (no changes of V & M), so time is not limited
                }
            }
          
            for (i = 0; i < ccf.Length; i++)//Starting the engine
            {//now it's time to measure the T_engine in accordance to periods of life
             //and compare it to T_overheat

                //The idea: 
                //1) Divide time periods by precision(for example: 1000) and count temperature raising for every timeBit
                //2) Do the same for temperature falling
                //3) Summarize both until the result is less than T_overheat
                //4) Break if overheat occured

                double timeBit = 0;
                int precision = 1000;

                if (i >= 0 && i < (ccf.Length -1))//while using periods before the last one
                {
                    timeBit = ccf[i].secondsDelta / precision;//1 Ofcourse timeBit could be of the same length for all periods, but historically it's counted like that :)
                    for (int j = 0; j < precision; j++)
                    {
                        T_engine += ccf[i].Vh * timeBit;
                        T_engine += (C * (T_outside - T_engine)) * timeBit;
                        if (T_engine >= T_overheat)
                        {
                            Console.WriteLine("The engine overheated after " + (ccf[i].secondFrom + (double)j * timeBit) + " seconds\n");
                            i = Int32.MaxValue;
                            break;
                        }
                    }
                    if (i == Int32.MaxValue) break;//breaks i-th for cycle
                }
                else if (i == (ccf.Length - 1))//after getting to the last period of time
                {
                    timeBit = 1 / (double)precision;//here just assigning timeBit as a constant and trying to run the engine for the maximum amount of time
                    for (int j = 0; j < Int32.MaxValue; j++)
                    {
                        T_engine += ccf[i].Vh * timeBit;
                        T_engine += (C * (T_outside - T_engine)) * timeBit;//2
                        if (T_engine >= T_overheat)
                        {
                            Console.WriteLine("The engine overheated after " + (ccf[i].secondFrom + (double)j * timeBit) + " seconds\n");
                            i = Int32.MaxValue;
                            break;//breaks the j-th for loop
                        }
                    }
                    if (i == Int32.MaxValue) break;//breaks i-th for loop
                }               
            }
        }
        static void Main(string[] args)
        {            
            while (true)
            {
                Console.WriteLine("Insert T_outside: ");
                try
                {
                    testEngineByT_outside(Convert.ToDouble(Console.ReadLine()));
                }
                catch (Exception)
                {
                    Console.WriteLine("Wrong input\n");
                }         

                /*Console.WriteLine("Insert time for engine to work: ");
                time = Convert.ToDouble(Console.ReadLine());
                testEngineByTime(time);*/
            }            
        }
        static void testEngineByTime(double timeInSec)//Just needed to implement something(this method) from my mind, to understand the task. This method can be deleted.
        {
            int i = 0;
            ccf = new CurrentCoeffs[M.Length];
            for (; i < M.Length; i++)
            {
                ccf[i] = new CurrentCoeffs();
                ccf[i].M = M[i];
                ccf[i].V = V[i];
                ccf[i].Vh = ccf[i].M * Hm + ccf[i].V * ccf[i].V * Hv;//the engine heats up by this formula(Celcius degrees per second)
                //ccf[i].Vc = C * (T_outside - T_engine);//the engine cools down by this formula(Celcius degrees per second)
                ccf[i].a = ccf[i].M / I;
                if (i != 0)
                {
                    ccf[i].secondFrom = ccf[i - 1].secondTo;//start of usage of current coefficients is at the end of previous period of time
                }
                if (i != M.Length - 1)
                {
                    deltaSpeed = V[i + 1] - V[i];
                    ccf[i].secondsDelta = deltaSpeed / ccf[i].a;
                    ccf[i].secondTo = ccf[i].secondFrom + ccf[i].secondsDelta;
                    //  ccf[i].tempGrowth = ccf[i].Vh * ccf[i].secondsDelta;
                }
                else
                {//maybe it's wrong to assign what's under...
                    ccf[i].secondsDelta = Double.MaxValue;//now there are no limits (no changes of V & M), so time is not limited
                }
            }
            //to understand how many periods of engine's life to apply to my time, I need to:
            T_engine = T_outside;
            int period = 0;
            double sOTLP = 0;//secondsOfTheLastPeriod
            i = 0;
            for (; i < ccf.Length; i++)
            {
                if ((ccf[i].secondTo > timeInSec) || (i == (ccf.Length - 1)))//... || if reached the end of the last period and time is still longer, than all the previous periods plus this one
                {
                    period = i;//have found the last period of engine's life to apply to the engine
                    sOTLP = timeInSec - ccf[i].secondFrom;//have found the number of seconds to apply during the last period
                    break;
                }

            }
            double timeBit = 0;
            int precision = 1000;
            i = 0;
            for (; i <= period; i++)//Starting the engine
            {//now it's time to measure the T_engine in accordance to periods of life
             //and compare it to T_overheat

                //The idea: 
                //1) Divide time periods by precision(for example: 1000) and count temperature raising for every timeBit
                //2) Do the same for temperature falling
                //3) Subtract both until the result is less than T_overheat
                //4) Break if overheat occured
                if (i >= 0 && i < period)//while using the whole periods
                {
                    timeBit = ccf[i].secondsDelta / (double)precision;//1
                }
                else if (i == period)//after getting to the last period of time
                {
                    timeBit = sOTLP / (double)precision;
                }
                else
                {
                    Console.WriteLine("i is out of bounds and equal to " + i);
                    break;
                }
                for (int j = 0; j < precision; j++)
                {
                    T_engine += ccf[i].Vh * timeBit;
                    T_engine += (C * (T_outside - T_engine)) * timeBit;//2
                    if (T_engine > T_overheat)
                    {
                        Console.WriteLine("The engine overheated after " + (ccf[i].secondFrom + (double)j * timeBit) + " seconds\n");
                        i = (Int32.MaxValue - 1);
                        break;
                    }
                }
                if (i == (Int32.MaxValue - 1)) break;
            }
            if (i != (Int32.MaxValue - 1))
            {
                Console.WriteLine("The engine hasn't overheated. It's temperature is: " + T_engine + "\n\n");
                i = 0;
            }

        }

    }
}
