
/**
* Setup for our Quiz
*
* @author  Noah Funderburgh
* @version 1.0
* @since   3/3/2020
*/

abstract class Question {
	protected String typeText;

//-------------------------------------------------------
	protected String levelText;

//-------------------------------------------------------
	protected String questionText;

//-------------------------------------------------------
	protected String answerText;

//-------------------------------------------------------
	protected boolean correct;

//-------------------------------------------------------
	/**
	 * This functions sets whatever type is equal to typeText so we
	 * can see what type of question we are dealing with.
	 * 
	 * @param type Used to set type of the question were dealing with.
   	 */
	void setType(String type) {
		typeText = type;
	}

	//-------------------------------------------------------
	/**
	 * This functions sets the level of the questions. valid lvls are 1-9 so 0 
	 * would not be valid.
	 * 
	 * @param Level Used to set the level of the question were dealing with.
   	 */
	void setLevel(String Level) {
		levelText = Level;
	}

	//-------------------------------------------------------
	/**
	 * This functions sets the question equal to questionText.
	 * 
	 * @param Question Used to set the question so we know what the question is.
   	 */
	void setQuestion(String question) {
		questionText = question;
	}

	//-------------------------------------------------------
	/**
	 * This function sets the answer equal to answerText
   	 */
	void setAnswer(String answer) {
		answerText = answer;
	}

	//-------------------------------------------------------
	/**
	 * This functions will show the answer when calling the function.
   	 */
	abstract void showQuestion();
	//-------------------------------------------------------
	/**
	 * This functions will show the answer when calling the function.
   	 */
	void showAnswer() {
		System.out.println(answerText);
	}

	//-------------------------------------------------------
	/**
	 * When calling this function it changes correct to true.
   	 */
	void markCorrect() {
		correct = true;
	}

	//-------------------------------------------------------
	/**
	 * This function checks the if userAnswer is equal to Answer by making both strings lowercase
	 * and then comparing the two to check if there equal.
	 * 
	 * @param userAnswer answer thats input by the user in the quiz
	 * @return boolean returns true if there equal else it returns false.
   	 */
	abstract boolean checkAnswer(String userAnswer);
	
}
//-------------------------------------------------------
