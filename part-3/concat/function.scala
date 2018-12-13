def concat(strings: String*) = {
    var result:String = ""
    for(s<-strings) {
        result += s
    }
    result
}
