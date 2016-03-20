func makeSortedDigitArray(x: Int) -> [Character] {
  let array = String(x).characters
  return array.sort()
}

func main() {
  var digitArray: [Character]
  
  for x in 5...500000 {
    digitArray = makeSortedDigitArray(2 * x)
    for multiplier in 3...6 {
      if digitArray != makeSortedDigitArray(multiplier * x) {
        break
      }
      print("x = \(x)")
      if multiplier == 6 {
        print("FOUND!!")
      }
    }
  }
}

main()
