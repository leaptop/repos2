using System;

namespace Mazes
{
    public static class EmptyMazeTask
    {
        public static void MoveOut(Robot robot, int width, int height)
        {

            {
                for (int i = 0; i < 100; i++)
                {
                    try
                    {
                        robot.MoveTo(Direction.Down);

                    }
                    catch (Exception e) { Console.WriteLine(e); };

                    try
                    {
                        robot.MoveTo(Direction.Left);

                    }
                    catch (Exception e) { Console.WriteLine(e); };
                    try { robot.MoveTo(Direction.Right); }
                    catch (Exception e) { Console.WriteLine(e); };
                }


            }
        }
    }
}
