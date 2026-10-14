# """
# This is the robot's control interface.
# You should not implement it, or speculate about its interface
# """
# class Robot:
#    def move(self):
#        """
#        Returns true if the cell in front is open and robot moves into the cell.
#        Returns false if the cell in front is blocked and robot stays in the current cell.
#        :rtype bool
#        """
#
#    def turnLeft(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def turnRight(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def clean(self):
#        """
#        Clean the current cell.
#        :rtype void
#        """

class Solution:
    def cleanRoom(self, robot):
        """
        :type robot: Robot
        :rtype: None
        """
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # up, right, down, left
        visited = set()
        
        def go_back():
            robot.turnRight()
            robot.turnRight()
            robot.move()
            robot.turnLeft()
            robot.turnLeft()
        
        def dfs(x, y, d):
            visited.add((x, y))
            robot.clean()
            for i in range(4):
                new_d = (d + i) % 4
                nx = x + directions[new_d][0]
                ny = y + directions[new_d][1]
                if (nx, ny) not in visited and robot.move():
                    dfs(nx, ny, new_d)
                    go_back()
                # turn the robot to face the next direction
                robot.turnRight()
        
        dfs(0, 0, 0)
