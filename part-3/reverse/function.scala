def reverse(str: String) = {
    var result:String = ""
    for(i <- str.length - 1 to 0 by -1) {
        result += str.charAt(i)
    }
    result
}
