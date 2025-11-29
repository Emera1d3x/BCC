# Bird Computing Contest 1 P1 - Enchanted Egg
> Did you know that *Struthio camelus*, better known as the ostrich, can lay eggs that have a volume of 1.2 liters - roughly 24 times the size of chicken eggs? <br>
While this is the largest among all living animals, it pales in comparison to the past, when the extinct elephant birds laid eggs reaching an astonishing 8 liters in volume.

A bird has created a nest and laid ~N~ eggs in a circular pattern. The eggs are numbered ~1~ through ~N~ clockwise.

Each character is either:
- `F` - Fertile (can hatch because there is a chick inside)
- `I` - Infertile (cannot hatch because there no chick inside)

You are given ~N~ characters representing the nest, where each character corresponds to an egg in the circular order.

For example, let ~N~ = ~12~ and the characters be `I`,`F`,`F`,`I`,`F`,`I`,`I`,`F`,`I`,`I`,`F`,`F`. If we colour the fertile eggs white and infertile eggs orange this is what the arrangement in the nest like:
<div style="text-align: center"><img src="https://static.dmoj.ca/media/martor/1b333996-0acb-42c8-8cf8-295a3eedd581.png" alt="Example" width="300"/></div>

Later, a magical griffin comes along and asks for your help. For ~Q~ queries, the griffin wants to know whether one of her enchanted eggs will hatch if she drops it into a subsection defined by the portion of the circular nest starting from egg ~S_i~ and ending at egg ~E_i~, inclusive and moving clockwise

The enchanted egg will hatch if the number of fertile eggs in the subsection is odd. (The enchanted egg yearns to bring balance).

Otherwise the enchanted egg will not hatch. 

For each query print `YES` if the enchanted egg will hatch or `NO` if the enchanted egg cannot hatch.

## Input Specification

The first line will contain 2 single spaced integers ~N~ and ~Q~, representing the number of eggs and queries.

The next line will contain ~N~ single spaced characters. Each character is either `F` or `I` representing whether it fertile or not.

The next ~Q~ lines will have 2 single spaced integers ~S_i~ and ~E_i~, representing the section of the nest the griffin is considering.

## Output Specification

For each ~Q~ print `YES` if the egg can hatch or `NO` if it can't. 


## Constraints

~1\le N \le 2\times10^7~ 

~1\le Q\le 2\times10^5~ 

~1\le S_i, E_i\le N~

### Subtasks 1 [20%]
~1\le N, Q \le 2\times10^2~
### Subtasks 2 [30%]
~1\le N, Q \le 2\times10^4~
### Subtasks 3 [50%]
No additional constraints.

## Sample Input 1
```
6 3
F F I F I F
1 4
3 6
5 3
```
## Output for Sample Input 1
```
YES
NO
YES
```
## Explanation of Output for Sample Input 1
If we colour the fertile eggs white and infertile eggs orange this is what the arrangement in the nest like:
<div style="text-align: center"><img src="https://static.dmoj.ca/media/martor/3c5421ea-b7f7-496d-a6a7-467db4e6752a.png" alt="Initial Condition" width="150"/></div>
 
The red arc shows which eggs are targeted in each query:
 
<div style="text-align: center;">
  <table style="margin: auto; text-align: center;">
    <tr style="text-align: center;">
      <th style="text-align: center;">Query 1</th>
      <th style="text-align: center;">Query 2</th>
      <th style="text-align: center;">Query 3</th>
    </tr>
    <tr>
      <td style="padding: 25px;"><img src="https://static.dmoj.ca/media/martor/6a8a9796-ced1-4184-8322-22f532d19d55.png" width="200"></td>
      <td style="padding: 25px;"><img src="https://static.dmoj.ca/media/martor/c407cd05-0927-416b-9d49-b632659c51d1.png" width="200"></td>
      <td style="padding: 25px;"><img src="https://static.dmoj.ca/media/martor/40e70ef5-db43-4d6d-bece-0752dde471a5.png" width="200"></td>
    </tr>
  </table>
</div>

For the first query ~S~ = ~1~ and ~E~ = ~4~ so the subsection in consideration is `F`,`F`,`I`,`F`. There is an odd number of fertile eggs so the enchanted egg will hatch.

For the second query ~S~ = ~3~ and ~E~ = ~6~ so the subsection in consideration is `I`,`F`,`I`,`F`. There is an even  number of fertile eggs so the enchanted egg will not hatch.

For the last query ~S~ = ~5~ and ~E~ = ~3~ so the subsection in consideration is `I`,`F`,`F`,`F`,`I`. There is an odd number of fertile eggs so the enchanted egg will hatch.
