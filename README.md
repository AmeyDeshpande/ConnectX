##Bugs -

1. A bug in this program is, in the inBound function.
This function is checking for height and width if they are in-bound that means they are not less than zero and not grater than
the set height and width.
First this function checks if the width is valid and then it checks for height. And this function uses same variable for both 
height and width, and return a value of this variable as valid or invalid.
Now, as it uses a same variable to validate height and width, first it will validate width, and now it will validate height and
update 'inside' variable. So, even if the width is not valid the function will go on to check for height, and if the height is valid
then it will return true.
e.g. if width is -12 and height is 10. It will validate width and set 'inside' variable a false value but later when it validates
height it will again set inside variable a true value and ultimately end up returning true where it should return false.

2. The second bug is, whenever we try to place a piece outside the board, it somehow manages to place it on the board.
Suppose, the board is of size 6*6, and we try to place a piece on 14th or -6th column, it should allow to place a piece.
But, in this case it places a piece on the board at any random place.
