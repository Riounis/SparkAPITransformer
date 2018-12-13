def hex(expr: String) = {
    var result:String = ""
    for(c<-expr) {
        val hexChar:String = Integer.toHexString(c)
        result += hexChar.toUpperCase()
    }
    result
}
