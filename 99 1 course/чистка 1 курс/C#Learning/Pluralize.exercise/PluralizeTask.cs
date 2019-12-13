namespace Pluralize
{
    public static class PluralizeTask
    {
        public static string PluralizeRubles(int count)
        {
            int n = count % 10;
            int z = count % 100;

            if ((z >= 11 && z <= 14) || n == 0 || (n >= 5 && n <= 9)) { return "рублей"; }
            else if (n >= 2 && n <= 4) { return "рубля"; }
            else return "рубль";
        }
    }
}