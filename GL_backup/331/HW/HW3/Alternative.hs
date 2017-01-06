module Alternative where
import Data.List
import Control.Applicative


{-
	Alternative.hs 
	Written by: Michael Schwarz Stuart Woodbury Neh Patel and Matthew Henry
     
        see Assignment3.hs

-}


{-produces all combinations-}
--http://www.haskell.org/haskellwiki/99_questions/Solutions/26
combinations :: Int -> [a] -> [[a]]
combinations 0 _ = [[]]
combinations _ [] = []
combinations n (x:xs) = (map (x:) (combinations (n-1) xs)) ++ (combinations n xs)

{-captures all groups with no two groups having students grouped more than once-}
reOccurances:: (Ord a) => [a] -> [a] -> Int
reOccurances xs ys
        | length xs == 0 = 0
        | length ys == 0 = 0
        | otherwise = length [x|x <- xs, elem x ys]

{-returns a list of all unique groupings
 TODO fix type error-}
getUnique :: [[Int]] -> [[Int]]
getUnique xs
          | length xs == 0 = [[]]
          | otherwise = do
            let x = head xs
            let y = tail xs
            return x : [z | z <- y, (reOccurances x z ) < 2] : [[]]

{-
	Checks if the total number of students can be split into said group size
-}
checkmod :: Int -> Int -> Bool
checkmod x y 
       | mod x y == 0 = True
       | otherwise = False

--http://stackoverflow.com/questions/932639/haskell-cant-use-map-putstrln
mapM_ :: Monad m => (a -> m b) -> [a] -> m ()