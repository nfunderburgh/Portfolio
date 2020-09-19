/**
* Implements classes need to add a short answer question
* Functionality to our Quiz
*
* @author  Noah Funderburgh
* @version 1.0
* @since   3/3/2020
*/

public class Questionsa extends Question{
	/**
	 * This functions will show the answer when calling the function for short answer questions.
   	 */
	void showQuestion() {
		System.out.println(questionText + "?");
	}

//-------------------------------------------------------
	/**
	 * This function checks the if userAnswer is equal to Answer by making both strings lowercase
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
		else {
			return false;
		}
	}
}