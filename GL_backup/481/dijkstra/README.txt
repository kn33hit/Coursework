Status report 
-> The program does not execute dijkstra's algorithm correctly

-> To compile and run use the Makefile 
      -> compile command: make 
      -> run command: ./Driver.out fileName.txt

-> The program can only take in 9 Nodes. To increase change the number
   of ARRAY_SIZE in Graph.h. It will change it throughout. However 
   it will still only print routing table for 8 nodes as that part is hard 
   coded 
-> The graph that I have used is the one that was provided in the homework.
-> To show my other efforts of making the perfect output.txt I created 
   a parent array which helped me output the correct outputs. However, in the 
   routing tables and total cost you can probably notice everything went 
   horribly wrong. I really tried over and over again to implement the 
   algorithm, but I was unsuccesful.
-> The routing table however would output the right outputs if the 
   dijkstra function (findPath()) worked correctly. It does work for some nodes
   but not for all. 
-> The manual parent array is in PrintResults, and to find it in the code 
   I've commented it as TEMP right above it. You can change it to parent[]
   array as that is what would've been there if dikjstra worked correctly.
   Furthermore it runs into an infinite loop.  
-> Plus the costs are slightly off as well. They seem to be added wrong things 
   sometimes. However it mataches up depending on the parent function. 
-> To get a better picture of the Node and their parent and the cost,
   uncomment the for loop at the bottom of findPath(). 
    I will include a picture of that so you dont have to do this

-> I started this project early however graphs are my biggest nemesis. It 
   seems there is a trend where I've suffered in coding Graph structures. 
   Have a great summer! :D 
