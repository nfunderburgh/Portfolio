

/**
 * Validates given text File and prints lineNumber - line and then the given
 * error with the line.
 *
 * @author Noah Funderburgh
 * @version 1.0
 * @since 3/3/2020
 */

// public class
public class Validate {
	/**
	 * The function checks to see if there are enough : for how many possible
	 * answers there are
	 * 
	 * @param
	 * @return
	 */
	static boolean isAnswerMuti(String line) {
		int countSemiColons = 0;
		if (line.charAt(0) == 'M' && line.charAt(1) == 'C' || line.charAt(0) == 'M' && line.charAt(1) == 'A') {
			for (int i = 0; i <= line.length() - 1; i++) {
				if (line.charAt(i) == ':') {
					if (line.charAt(i + 1) == ':') {
						return true;
					}
					countSemiColons++;
				}
			}
			countSemiColons++;
			char isLower = (char) (countSemiColons + 'a');
			char isUpper = (char) (countSemiColons + 'A');
			int size = line.length();
			int i = 1;
			while (line.charAt(size - i) != '|') {
				int delim = size - i - 1;
				if (line.charAt(size - i) >= 'a' && line.charAt(size - i) < isLower) {
					if (line.charAt(delim) == '|')
						return false;
				}
				if (line.charAt(size - i) >= 'A' && line.charAt(size - i) < isUpper) {
					if (line.charAt(delim) == '|')
						return false;
				} else {
					return true;
				}
				i++;

			}
		} else {
			return false;
		}
		return false;
	}

//-------------------------------------------------------
	/**
	 * The function checks to see the question contains a valid quest type current
	 * ones are MC MA SA TF
	 * 
	 * @param line - This is the line were checking
	 * @return boolean - This return true if type is correct and false otherwise
	 */
	static boolean isType(String line) {
		int total = 0;
		if (line.charAt(0) != 'M' || line.charAt(1) != 'C')
			total++;
		if (line.charAt(0) != 'M' || line.charAt(1) != 'A')
			total++;
		if (line.charAt(0) != 'S' || line.charAt(1) != 'A')
			total++;
		if (line.charAt(0) != 'T' || line.charAt(1) != 'F')
			total++;
		if (total == 4) {
			return true;
		} else {
			return false;
		}
	}

//-------------------------------------------------------
	/**
	 * The function checks to see if the line in the text file is spaced correctly
	 * such as having : is its MC MA or if there are enough delimiters in the line
	 * 
	 * @param line - This is the line were checking
	 * @return boolean - This returns true if the line is spaced correctly and false
	 *         otherwise
	 */
	static boolean spacedCorrect(String line) {
		int countMultiQuestions = 0;
		int countSpacers = 0;
		if (line.charAt(2) != '|' || line.charAt(4) != '|') {
			return true;
		}
		for (int i = 0; i <= line.length() - 1; i++) {
			if (line.charAt(0) == 'T' && line.charAt(1) == 'F' || line.charAt(0) == 'S' && line.charAt(1) == 'A') {
				if (line.charAt(i) == ':') {
					return true;
				}
			}
			if (line.charAt(i) == ':') {
				countMultiQuestions++;
			}
			if (line.charAt(i) == '|') {
				countSpacers++;
			}
		}
		if (line.charAt(0) == 'M' && line.charAt(1) == 'C' || line.charAt(0) == 'M' && line.charAt(1) == 'A') {
			if (countSpacers != 4) {
				return true;
			}
		}
		if (line.charAt(0) == 'T' && line.charAt(1) == 'F' || line.charAt(1) == 'S' && line.charAt(1) == 'A') {
			if (countSpacers != 3) {
				return true;
			}
		}
		return false;
	}

//-------------------------------------------------------
	/**
	 * This function checks the level of the line and if its 0 it will return false
	 * otherwise its good. if a user puts in a two digit num the spacedCorrect
	 * fuction will count it as a spacing issue.
	 * 
	 * @param line - This is the line were checking
	 * @return boolean - This return true if type is level is 1-9 else false.
	 */
	static boolean isLevel(String line) {
		if (line.charAt(3) == '0') { // 1-9 is our level range
			return true;
		}
		return false;

	}

//-------------------------------------------------------
	/**
	 * This function checks for two comment types within the text file # & // if
	 * either of these are caught the WHOLE line will be ignored.
	 * 
	 * @param line - This is the line were checking
	 * @return boolean - true if there are no comments, false if we found a comment
	 *         line.
	 */
	static boolean isComment(String line) {
		if (line.charAt(0) == '#') {
			return false;
		} else if (line.charAt(0) == '/' && line.charAt(1) == '/') {
			return false;
		} else {
			return true;
		}
	}

//-------------------------------------------------------
	/**
	 * This function checks if its TF question and if it is then is the answer True
	 * or false.
	 * 
	 * @param line - This is the line were checking
	 * @return boolean returns true if answer is true or false, and if not it
	 *         returns false.
	 */
	static boolean isTF(String line) {
		int size = line.length();
		int i = 1;
		if (line.charAt(0) == 'T' && line.charAt(1) == 'F') {
			while (line.charAt(size - i) != '|') {
				int delim = size - i - 1;
				if (line.charAt(size - i) != 'T' && line.charAt(size - i) != 'F' && line.charAt(size - i) != 't' && line.charAt(size - i) != 'f') {
					if (line.charAt(delim) == '|') {
						return true;
					}
				} else {
					return false;
				}
				i++;
			}
		}
		return false;
	}

//-------------------------------------------------------
	/**
	 * This function checks each of the individual functions and to see if there
	 * true, If one is true the function returns true meaning the line has a error.
	 * If there are multiple errors or one error it will still return true.
	 * 
	 * @param line - This is the line were checking
	 * @return boolean returns false if text file is valid, returns true is we found
	 *         a error
	 */
	static boolean isTextValid(String line) {
		if (isType(line)) {
			return true;
		}
		if (spacedCorrect(line)) {
			return true;
		}
		if (isLevel(line)) {
			return true;
		}
		if (isAnswerMuti(line)) {
			return true;
		}
		if (isTF(line)) {
			return true;
		}
		return false;
	}

//-------------------------------------------------------	
	/**
	 * This function runs each function and if the function returns true then it
	 * prints the error statement. Warning if there are multiple errors only one
	 * error will be displayed.
	 * 
	 * @param line - This is the line were checking
	 */
	static void errorMessages(String line) {
		if (isLevel(line)) {
			System.err.print("Question level Invalid\n");
		}
		if (isType(line)) {
			System.err.print("Question Type Invalid\n");
		}
		if (spacedCorrect(line)) {
			System.err.print("Question spacing Invalid\n");
		}
		if (isAnswerMuti(line)) {
			System.err.print("Question Multi Choice Invalid\n");
		}
	}

//-------------------------------------------------------
	/**
	 * This function runs isComment then isTextValid and if both return true then it
	 * prints the line number and the line of the error. It also runs errorMessages
	 * to get a description of the error with the line.
	 * 
	 * @param line    - This is the line were checking
	 * @param lineNum - This is what line we are one in the text file.
	 */
	static boolean isValid(String line, int lineNum) {
		if (isComment(line)) {
			if (isTextValid(line)) {
				System.err.print("Line " + lineNum + " - ");
				System.err.println(line);
				errorMessages(line);
				System.err.print("\n");
				return false;
			}
		}
		return true;
	}
}
//-------------------------------------------------------