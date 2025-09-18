-- HEADER
module SecondLargest where

max2 :: Int -> Int -> Int

max2 a b =
    if a >= b then a
    else b

findLargest :: [Int] -> Int

findLargest l = 
    if (length l) == 1 then head l
    else max2 (head l) (findLargest (tail l))

delNInList :: [Int] -> Int -> [Int]
delNInList l n =
    if (length l) == 0 then []
    else if (head l) /= n then (head l) : delNInList (tail l) n
        else delNInList (tail l) n 

secondLargest :: [Int] -> Int

secondLargest l =
    let
        lrg = findLargest l 
    in 
        findLargest (delNInList l lrg)



