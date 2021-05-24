<h2> Convert an array into Strictly Increasing Array </h2>
<i> Solution by Udit Gupta </i>

</br>
<br>

<h3> Problem Statement </h3>

Given an array consisting of <b> N </b> elements namely from A<sub>1</sub> to A<sub>N</sub>. You have to convert this array to <strong>strictly increasing </strong> array in not more than <strong> K</strong> cost. 
Operations allowed :
1. Increase an element by 1.
2. Decrease an element by 1.

Cost of each operation is 1 unit.

</br>

<h3> Constraints </h3>

- <b> N < 3000 </b>
  
- <b> K < 5000 </b>
  
- <b> |A<sub>i</sub>| < 10<sup>9</sup> </b> for all i from 1 to N.
  
</br>

<h4> Expected Time Complexity : O(N<sup>2</sup>) </h4>
  
  </hr>
  </br>
  
<br>

<h3> Solution </h3>

<h4> Observation </h4>
  <p>
    
  1. After solving a few examples on pen and paper, we get to see that a greedy solution would fail on cases like [8, 1, 2, 3, 4] or [7, 1, 5, 2, 4, 8, 6].
  
  2. Another key observation is that in the transformed array which is strictly increasing, we will find that  there is atleast one element which remains unchanged. 
  </p>
  
<h4> Deduction </h4>

The problem statement above can be translated into simpler terms by stating that 

for each i from _1_ to _N-1_,  &nbsp; **A<sub>i</sub> &nbsp; < &nbsp; A<sub>i+1</sub>**

Now we shall work on simplifying it further and deducing a general formula for all terms, 

**A<sub>i</sub> &nbsp; &le; &nbsp; A<sub>i+1</sub> - 1**

- Subtracting i from both sides, 

**A<sub>i</sub>-i &nbsp; &le; &nbsp; A<sub>i+1</sub>-1-i**

_or_

**A<sub>i</sub>-i &nbsp; &le; &nbsp; A<sub>i+1</sub>-(i+1)**

This is the general formulation which should work for all indices in range [1, N].
i.e.  

The sequence represented by (A<sub>i</sub>-i) &nbsp; &forall; &nbsp; i &isin; [1, N] should be a **non decreasing sequence**.

To achieve this we take use of dynamic programming and brute force our way to make the subsequent array element equal to the previous one if not or leaving it as it is depending on the previous dp state. 

This idea, here, comes from observation 2 and we can even end up converting the whole array to a single element. 


DP transition states:

**dp[j] = min(dp[j-1], dp[j] + abs(A[i] - A[j]))** &nbsp; &forall; &nbsp; i, j &isin; [1, N]. 

Please note that the array **A** here is the converted array represented by (A<sub>i</sub>-i) &nbsp; &forall; &nbsp; i &isin; [1, N]. 

Our final answer that represents the minimum cost is stored in the final index of our **dp** array which represents the optimal array till last index of **A**.

If our minimum cost is not more than **K** then we can certainly achieve the optimal solution.

Note : This dp solution can be made more state verbose by storing the brute forced optimal substructure into their respective states in dp[i][j] but I prefer it this way. 

<!--  C++ code  -->
<details>
  <summary> CODE (C++) </summary>
    ```ruby
    require 'redcarpet'
    markdown = Redcarpet.new("Hello World!")
    puts markdown.to_html
    ```
</details>

<!--  Python code  -->
<details>
    <summary> Code (Python) </summary>

    ```python
      
    print("hello world!")
      
    ```
</details>



Time Complexity : O(N<sup>2</sup>)

Space Complexity : O (N)




  
  
