### 1. H1 — Range Exclusion Using Difference Array

> **Idea:** if i want that in this to this range nothing should be there then we will use ideas that is (i-l positon ++  and i + r position  - - ) that all .

- Increment the position just before the range: `diff[i - l]++`
- Decrement the position just after the range: `diff[i + r + 1]--`

This allows us to handle range updates efficiently without explicitly modifying every element inside the range.

-------

### 2. H2 
> **Idea:** [leetcode](https://leetcode.com/problems/valid-parenthesis-string/description/?envType=daily-question&envId=2026-10-04)  we use two pointers (left then right) too . always break things into numbers , +1 ,-1 , 0 in this to mtlb ye h ki agr 0 bhi rkhu aur ek side se bs +1 dekhu then there is no issue such . so ≥0 true .mainly i m focused now like that 

-----

### 3. H3




----
