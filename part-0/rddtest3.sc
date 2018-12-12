var wordList = sc.textFile("beemoviescript.txt").flatMap(line => """[\p{Punct}]""".r.replaceAllIn(line, "").split(" ")).map(word => word.capitalize).collect()
wordList.filter(word => if(word != null && word.length > 0) word.charAt(0) == 'B' else false).foreach(println)
