
/**
* Implements classes need to add a True False question
* Functionality to our Quiz
*
* @author  Noah Funderburgh
* @version 1.0
* @since   3/3/2020
*/

public class Questiontf extends Question{
	/**
	 * This functions will show the answer when calling the function for true false questions.
   	 */
	void showQuestion() {
		System.out.println(questionText + " (True of False?)");
	}

//-------------------------------------------------------
	/**
	 * This function checks the if userAnswer is equal to Answer by making both strings lower case
	 * and then comparing the two to check if there equal.
	 * 
	 * @param userAnswer answer thats input by the user in the quiz
	 * @return boolean returns true if there equal else it returns false.
   	 */
	boolean checkAnswer(String userAnswer) {
		userAnswer = userAnswer.toLowerCase();
		answerText = answerText.toLowerCase();
		if(answerText.equals(userAnswer)) {
			return true;
		}
		if( answerText.contentEquals("true") && userAnswer.contentEquals("t") ) {
			return true;
		}
		if( answerText.contentEquals("false") && userAnswer.contentEquals("f") ) {
			return true;
		}
		else {
			return false;
		}
	}
}
