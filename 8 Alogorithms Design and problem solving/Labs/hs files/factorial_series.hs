fac_series::Int -> Int
fac_series n 
    | n > 1 = n * fac_series (n - 1)
    | otherwise = 1