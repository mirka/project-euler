import Foundation

let digits: Double = 10
let cutoff = Int( pow(Double(10), digits) )

func cutoffDigits(var total: Int) -> Int {
  while total > cutoff {
    total = removeFirstDigit(total)
  }
  return total
}

func removeFirstDigit(total: Int) -> Int {
  let string = String(total)
  let shortenedString = String(string.characters.dropFirst())
  return Int(shortenedString)!
}

func getSelfPowerLastDigitsOf(n: Int) -> Int {
  var total = n
  
  for _ in 1..<n {
    total = cutoffDigits(total * n)
  }
  return total
}

func addSelfPowersFrom(start: Int, to end: Int) -> Int {
  var total = 0;
  
  for n in start...end {
    total += getSelfPowerLastDigitsOf(n)
    cutoffDigits(total)
  }
  return total
}

print(addSelfPowersFrom(1, to: 1000))
