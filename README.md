# Filler
Filler is an algorithmic game which consists in filling a grid of a known size in advance with pieces of random size and shapes, without the pieces being stacked more than one square above each other and without them exceeding the grid.

If one of these conditions is not met, the game stops.

Each successfully placed piece yields a number of points, and has only one player, the goal of the game could be to get the best score possible. 

However, it is with two players that the filler takes all his interest. Each player has for the purpose of placing as many
pieces as possible while attempting to prevent his opponent from doing the same. At the end of the game, the one with the most points wins the match.

I made my own player which calls **"lpohribn.filler"!**. Project also has a visualization part, which was realized by **SDL**!

# Usage
**./resources/filler_vm -p1 [name player].filler -p2 resources/players/[name player].filler -v -f resources/maps/[map]**

with visualization:
**./resources/filler_vm -p1 [name player].filler -p2 resources/players/[name player].filler -v -f resources/maps/[map] | ./viz_fill/visualizer**
(play/pause button - space)

# Visualization

![Alt Text](https://github.com/lpohribn/Filler/blob/master/additional_file/image.gif)
