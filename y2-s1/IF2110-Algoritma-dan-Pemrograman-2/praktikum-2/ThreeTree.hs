--HEADER
module ThreeTree where

--DEFNISI DAN SPESIFIKASI UTAMA
threeTree :: [Int] -> [Int]
-- threeTree(l) akan menerima sebuah list berisi bilangan bulat dan mengembalikan isi yang kelipatan 3

threeTree l =
    if (length l) == 0 then []
    else if (head l) `mod` 3 == 0 then (head l) : (threeTree (tail l))
    else threeTree (tail l)
