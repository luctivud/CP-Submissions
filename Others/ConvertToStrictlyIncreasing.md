<h2> Convert an array into Strictly Increasing Array </h2>
<i>- by Udit Gupta </i>

</br>

<h3> Problem Statement </h3>

Given an array consisting of <b> N </b> elements namely from A<sub>1</sub> to A<sub>N</sub>. You have to convert this array to <strong>strictly increasing </strong> array in not more than <strong> K</strong> cost. 
Operations allowed :
1. Increase an element by 1.
2. Decrease an element by 1.

Cost of each operation is 1 unit.

</br>

<h3> Constraints </h3>

<b> N < 3000 </b>
  
<b> K < 5000 </b>
  
<b> |A<sub>i</sub>| < 10<sup>9</sup> </b> for all i from 1 to N.
  
</br>

<h4> Expected Time Complexity : O(N<sup>2</sup>) </h4>
  
  </ hr>
  </ br>
  

<h3> Solution </h3>

<h4> Observation </h4>
  <p>
    1. After solving a few examples on pen and paper, we get to see that a greedy solution would fail on cases like [8, 1, 2, 3, 4] or [7, 1, 5, 2, 4, 8, 6].
    
    2. Another key observation is that in the transformed array which is strictly increasing, we will find that  there is atleast one element which remains unchanged. 
  </p>
  
<h4> Deduction </h4>

The problem stated above can be translated into simpler terms by stating that 
for each i from _1_ to _N-1_, 
A<sub>i</sub> < A<sub>i+1</sub>

Now we shall work on simplifying it further.
A<sub>i</sub> \leqslant A<sub>i+1</sub> - 1

- Subtracting i from both sides, 
A<sub>i</sub> - i \leqslant A<sub>i+1</sub> - 1 -  i

_or_

A<sub>i</sub> - i \leqslant A<sub>i+1</sub> - (i + 1)

This is a general formulation which should work for all indices in range [1, N].


  
  
