module SlidingWindow where

konso:: a -> [a] -> [a]
konso e l = e : l

konsDot:: [a] -> a -> [a]
konsDot l e = l ++ [e]


isEmpty:: [a] -> Bool
isEmpty l = null l

nbElement:: [a] -> Int
nbElement l = if isEmpty l then 0 else 1 + nbElement (tail l)

{-|
  TakeN menerima sebuah integer n dan sebuah list l, dan menghasilkan sebuah list yang berisi n elemen pertama dari l. Jika n lebih besar dari panjang l, maka dihasilkan l itu sendiri.
  Prekondisi: n >= 0, l bisa kosong.
-}
takeN:: Int -> [a] -> [a]
takeN n l 
    | isEmpty l = []
    | n == 0 = []
    | otherwise = konso (head l) (takeN (n -1) (tail l))

{-|
  Deskripsi:
  Fungsi slidingWindow menerima sebuah integer ukuran window n prekondisi : 0 < n <= panjang xs,
  sebuah fungsi pemroses f, dan sebuah list xs, prekondisi : panjang xs > 0. Fungsi ini akan
  menghasilkan sebuah list baru yang berisi hasil dari penerapan
  fungsi f ke setiap window dengan ukuran n. Dapat menggunakan fungsi takeN.

  Contoh:
  slidingWindow 3 windowRange [1, 2, 3, 4, 5] akan menghasilkan [2, 2, 2]
-}

windowRange:: [Int] -> Int
windowRange l =
    if (isEmpty l) then 0
    else (maximum l) - (minimum l) 

-- TODO

slidingWindow :: Int -> ([a] -> b) -> [a] -> [b]
slidingWindow n f xs 
    | (length (xs)) == n = [f (takeN n xs)]
    | otherwise = konso (f (takeN n xs)) (slidingWindow n f (tail xs))

{-|
  Deskripsi:
  Fungsi windowRange menghasilkan selisih antara nilai maksimum dan nilai minimum dari list tersebut.
  nilai minimum dari list tersebut.

  Contoh:
  windowRange [1, 2, 3, 4, 5] akan menghasilkan 4
-}

