-- HEADER
module RunLengthEncoding where

isNextSame :: String -> Bool
isNextSame s = 
    if (length s) < 1 then False
    else (head s) == head (tail s)

removeFirstSame :: String -> String
removeFirstSame s =
    if (length s) == 1 then []
    else if (isNextSame s) == True then removeFirstSame (tail s)
    else (tail s)

countOccur :: String -> Int
countOccur s = 
    if (length s) == 0 then 0
    else if (length s) == 1 then 1
    if (isNextSame s) == False then 1
    else 1 + countOccur (tail s)

generateEncoding :: String -> (Char, Int)
generateEncoding s = 
    let
        hd = (head s)
    in
        if (length s) == 1 then (hd, 1)
        else (hd,(countOccur s))

-- DEFINISI DAN SPESIFIKASI UMUM
runLengthEncoding :: String -> [(Char, Int)]
-- runLengthEncoding(s) akan menerima string S dan membuat RLE dari string tersebut menggunakan pasangan char sebagai huruf dengan int sebagai jumlah kemunculan integer secara terurut

runLengthEncoding s = 
    if (length s) == 0 then []
    else if (length s) == 1 then [(head s, 1)]
    else (generateEncoding s) : (runLengthEncoding (removeFirstSame s))

