def day(date: String) : String = {
    var result:String = ""
    if(date.charAt(8) != '0') {
        result += date.charAt(8)
    }
    result + date.charAt(9)
}
