using TestingRoom;

namespace Mazes
{
    public static class EmptyMazeTask
    {
        public static void MoveOut(Robot robot, int width, int height) { 
        //{i == "empty1")
           if(robot.X==1)
            {
                robot.MoveTo(Direction.Down);
                robot.MoveTo(Direction.Right);
            }
            robot.MoveTo(Direction.Down);
        }
    }
}