module Power where

-- isPowerOf n base bernilai True jika n = base ^ k
-- dengan n dan base adalah bilangan asli
-- dan k adalah bilangan bulat nonnegatif
-- contoh: isPowerOf 27 3 = True (3^3 = 27)
-- contoh: isPowerOf 1 5 = True (5^0 = 1)
-- contoh: isPowerOf 5 10 = False

-- DEFINISI DAN SPESIFIKASI UTAMA
isPowerOf :: Int -> Int -> Bool
isPowerOf n base = 
    if base <= 1 then n == 1 -- Basis
    else if n == 0 then False
    else if n == 1 then True
    else if n `mod` base /= 0 then False
    else isPowerOf (n `div` base) base -- Rekursi