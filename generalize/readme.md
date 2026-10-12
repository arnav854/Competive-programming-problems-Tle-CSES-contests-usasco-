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
>**IDEA** braking thing into two sets that there is no relation of the elemenets in the same set or connected but have relation with other set —> biparitite 

----
### 4. H4 
>**IDEA** dsu be like is there relation direct or indirect with him or not in dynamically changes things may be after some time we get  . its main thing is to find components that r not connected and also those that will be joint to other dynamically .

---
### 5. H5
>**IDEA** path compression in this thing used in dsu but if we think properly then path compression is used when only one thing matter like in dsu only matter is root so compress ur path .

--- 
### 6. H6 
>**IDEA** in directed graph if ask bipartitness then do it as same as that we do in indirected graph as bcz of the reason is that since node A , B , C —>    like  A → B → C then overall A has relation with B and B relation with C or adjacent somehow and also bupartitiness def is that divide into two sets such that there is no directe rel in same set so thats why

---
### 7. H7 
>**IDEA** minimum spanning tree only wants that the all the cost of the path should be minimum thats it if doesnt care about node to node ( min dist )it only cares about if total cost of building such that atleast one path is there to trvael  

--- 
### 8. H8
>**IDEA** [codeforces] (https://codeforces.com/problemset/problem/1648/Ain) this problem what is done actually is like isme cordinates se dekha lets take an example → 3 6 8 as x cords so (8-6)*2 + rest tera 6 ne smbhal liya vaise kyunki 8 ne 6 ko dekha phele then utne se bs 2 jyada vhi 6 bhi usse dekhega . isliye (Sum of distances/differences between every pair  ) so for such type of things we apply this so first we think can we sort if we can then apply my idea 

---
### 9. H9 
>**IDEA** in an array if we have some pts and we need to bring some pts to other like combining or like finding the distance such that overall dist is min we go with median like go to the middle pt . this is the approach that we uses .

--- 
### 10. H10
>**IDEA** [codeforces] (https://codeforces.com/contest/1513/problem/B) in this problem actually what i was doing that since we need to do permutation without any thinking only thinking about permutations this is not how permutation or any problem get solved . — so first i think what if we think and see what can be grouped and what cant bit we cant do that . then if we move from taking one lemenet , then 2 element like that but i thinking what if number are permuting again and again so hence we cant do . But actually what we can think then ? dekh partition h  hi thenm lets break into actual small example or ek aur ki prefix and suffix way mein bhi sock skta hu but lets break . a1 = a2 & a3  &a4 . and mein likha hua hu ki a1&a2&a3&a4 = X . a1&a1 = a1&a2…. ⇒ a1 = X if i go with a1 &a2 = X ⇒ X & a2 = X ⇒ so its not necessary ki a2 = X ho but a1 ke jha bhi bit pr 1 h a2 bhi ho and also in X a2 and a1 comes so we are sure so whatever value caan be for a2 not issue . and so on we do .

--- 
### 11. H11 
>**IDEA** c(i+1)−ci=bc(i+1)−bc whenever u see this statemnet like maths statement just take  do this c(i+1)-bc(i+1) = …  like this and take things into indexes form like now u know what i mean . 

-- 
### 12. H12 
>**IDEA** if there is some problem that is related to hmm like subarray type that is ( l ,r ) find me this or that then think an option of pf(r) - pf(l) that is prefix i mean . 

--- 
### 13. H13
>**IDEA** [codeforces](https://codeforces.com/problemset/problem/1915/F) in this problem there is a situation i was into that is like i  have interval and inside one interval if there is a complete overshadowed interval that is (1 , 9) ← (2,8) where (2,8) inside this so we have an answer so how to do ? since it  is sorted so if it is sorted from first i dont care of first i care of second then if i get to know which numbers are actually lesse than second then i can see ya they r inside that and then i will remove this is what i needed so thats why i used multiordered_set for this  .So if we geeneralize things then we can say that if one thing has to be another thing and we need to calc then we use this .

---
### 14. H14 
>**IDEA** [codeforces](https://codeforces.com/problemset/problem/1872/E) in this problem i was continuouslt thinking about how to handle multiple chnages like i have to do multiple changes and i didnt break the problem and observe my only aim was how to do that but many or always mostly there is situtaton where u need to observe and big problem like how to do it resollves up by trick that u observe so break the solution not think how to continuously change if nothing comes then we can think . and what i learn is from here in XOR what u think is trick like same xor deleted so from that so that same perspective i have used .

---
### 15. H15 
>**IDEA** dp is like see multiple states transition and then take decision and believe in ur state 

--- 
### 16. H16 
>**IDEA** [codeforces](https://codeforces.com/problemset/problem/1776/L)we have 2 numbers and from 2 numbers we can take some amount to be positive and some to be negative so we need to make it 0 atlast so -> example : add ->+3 subs->4 and nums 5 , 9so  what i did -> +9 +9 +9 -9 -9 -9 -9 => val is then if i got neg that mean we need to replace 9 in such a way that (9-5)=> 4 will be reduced -> if val % 4 == 0 then we can think else no but if its % then how many negs are there if lesser yes else no 

--- 
### 17. H17 
