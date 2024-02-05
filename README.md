![Screencast from 05-02-2024 00 12 35(3)(1)(1)](https://github.com/rmnina/push_swap/assets/118455014/7b5e0fbb-c8a6-442d-94b0-e2a976c0d707)

(visualizer found here : https://github.com/o-reo/push_swap_visualizer)

# Instructions

Push_swap is a small algorithmic project which, thanks to very restrictive instructions, encourages us to write our own algorithm.

Here's the problem to be solved:

- A list of values to be sorted is sent to a stack A ;
- These values can be transferred to a stack B;
- However, these transfers can only be made in the following ways:
    - The first value of a stack can be sent to the top of the other stack (**push**);
    - The first two values of a stack can be swapped (**swap**);
    - The first value of a stack can be sent to the end of that same stack (**rotate**);
    - The last value of a stack can be sent to the top of that same stack (**reverse rotate**);
    - We can perform a **swap**, **rotate** or **reverse rotate** on both stacks at the same time.
    - And... that's all.
- The number of moves is **counted**. So, to get all the points on the project, the algorithm must not exceed :
    - For 3 values: **3 moves** ;
    - For 5 values : **12 moves** ;
    - For 100 values : **700 strokes** ;
    - For 500 values: **5500 moves**.
    
    All the moves made by the algorithm must therefore be printed out.
    

So basically, we have someting like this :

![Screenshot from 2024-02-05 02-13-27](https://github.com/rmnina/push_swap/assets/118455014/1edaa0e8-d1d4-43c1-8440-427505db2dec)

Although we don't have the luxury to enjoy 3 stacks... We only get 2… 🥲

As well as encouraging us to find our own algo, push_swap introduces us to the notion of **algorithmic complexity**. Here, it's **time complexity** that interests us: this means we don't care about the space or resources our program will consume, we're only interested in ensuring that its execution **costs the fewest operations possible**. This is where optimization comes in.

# Resolution

*My algorithm isn't perfect yet. It passes with flying colors the 100 values with an average of 630 hits, but it lacks a small optimization on the 500-value sort, which sorts in an average of 5700 hits. I PROMISE to add this opti one of these days. That said, I think it works pretty well.*

To comply with the project's instructions, we had to implement a small algo specifically for lists of 3 values, to be able to sort them in 3 moves max. This gives us an **algorithmic complexity of O^n in the worst case (linear complexity)**, which is WILD, clearly the best we can do. So I've decided to take this little algo as a basis, and **divide my values into chunks of 3**. These chunks will be determined by the space that the values must have once sorted. For example, if my list to be sorted is :

```markdown
./push_swap 6 74 47 12 91 16
```

6, 12 and 16 will be in chunk 1, and 47, 74 and 91 will be in chunk 2. Got it? For the moment, we haven't made any movements, just calculations

The next step was to send the values **already ordered by chunks** to the B stack. To keep this operation cost-effective, I've integrated cost calculation functions. These functions run through my two stacks, and **count for each element in stack A the number of moves required to position it correctly in stack B**. Here again, a lot of calculation, but no movement. The algo will then send the least costly value to stack B.

Once stack A is empty, the values are placed in stack B, in the reverse order of their chunk (since the top of B will go into the bottom of A). However, they're not quite sorted yet, so how to send it all back properly... Wait... We've got chunks of 3 values... **Didn't we have a super-optimized little algo to sort the values 3 by 3??** 🙂

Of course, we had to add the cost of pushing from B to A (which we couldn't really have done without anyway), but from the moment everything is in B, **the algo has finished most of its computational work and only has to apply its little algorithm to the groups of 3**. And it's sorted! 🙂
