module CountOccurrence where

-- count(ListOfList, n) menghitung berapa kali integer n muncul di dalam sebuah list of list.
-- CONTOH: count [[1,2,1],[3],[1,4]] 1 menghasilkan 3
count :: [[Int]] -> Int -> Int
-- TODO : implementasi fungsi count 

countInList :: [Int] -> Int -> Int
countInList l n =
    if (length l) == 0 then 0
    else if (head l) == n then 1 + (countInList (tail l) n)
    else countInList (tail l) n

count listOfList n =
    if (length listOfList) == 0 then 0
    else countInList (head listOfList) n + count (tail listOfList) n