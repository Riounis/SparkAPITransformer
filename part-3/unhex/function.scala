def unhex(expr: String) = {
    var result:String = ""
    val temp:String = expr.toUpperCase()
    for(i <- 0 to temp.length by 2) {
        try {
            var temp2:String = "" + temp.charAt(i) + temp.charAt(i+1)
            result += Integer.parseInt(temp2, 16).toChar
        } catch {
            case _: Throwable => null
        }
    }
    new String(result.getBytes(), "UTF-8")
}
