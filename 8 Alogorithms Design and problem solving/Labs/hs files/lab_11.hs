myMax::Int -> Int -> Int
myMax x y
   |    x > y    = x
   |   otherwise = y

maxThree:: Int -> Int -> Int -> Int
maxThree x y z
    | x > y && x > z = x
    | y > z          = y
    | otherwise      = z

myMin::Int -> Int ->Int
myMin x y
  | x < y = x
  | otherwise = y

minThree:: Int -> Int -> Int -> Int
minThree x y z
    | x < y && x < z = x
    | y < z          = y
    | otherwise      = z

calcPay:: Float -> Float -> Float 
calcPay h r z
    | (h * r) = z
