module ColumnOperations where 

konsdot :: [Int] -> Int -> [Int]
konso :: Int -> [Int] -> [Int]
isEmpty :: [Int] -> Bool

-- REALISASI
konso e l = [e] ++ l
konsdot l e = l ++ [e]
isEmpty l = null l

max2 :: Int -> Int -> Int
max2 a b = if a >= b then a else b

min2 :: Int -> Int -> Int
min2 a b = if a <= b then a else b

maxList :: [Int] -> Int
maxList l =
    if (length l) == 1 then last l
    else max2 (last l) (maxList (init l))

minList :: [Int] -> Int
minList l =
    if (length l) == 1 then last l
    else min2 (last l) (minList (init l))

sumList :: [Int] -> Int
sumList l =
    if (length l) == 0 then 0
    else (head l) + sumList(tail l)

-- Lengkapi Fungsi di bawah ini
columnOperations :: [[Int]] -> [Int]

columnOperations listOfList  
    | length listOfList == 0 = []
    | isEmpty (head listOfList) = []
    | (length (head listOfList)) >= 3 = 
        let
            firstCol = map head listOfList
            secCol = map head (map tail listOfList)
            thirdCol = map head (map tail (map tail listOfList))
            rest =  map tail (map tail (map tail listOfList))
        in
            [(maxList firstCol)] ++ [(minList secCol)] ++ [(sumList thirdCol)] ++ (columnOperations rest)
    | (length (head listOfList) == 2) = 
        let
            firstCol = map head listOfList
            secCol = map head (map tail listOfList)
        in
            [(maxList firstCol)] ++ [(minList secCol)]
    | (length (head listOfList) == 1) = 
        let 
            firstCol = map head listOfList
        in
            [maxList firstCol]
    | otherwise = []