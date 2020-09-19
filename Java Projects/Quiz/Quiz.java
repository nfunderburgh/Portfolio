import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Vector;

/**
 * Implements steps to setup the quiz and give the user the quiz along with
 * telling the user whether there right or wrong. It also allows them to re take
 * it up to 100%
 *
 * @author Noah Funderburgh
 * @version 1.0
 * @since 3/3/2020
 */

public class Quiz {
	/**
	 * This is main which runs the quiz.
	 * 
	 * @param args - should be text file and second argument should be -d if you
	 *             would like a dump of the questions & answers.
	 */
	public static void main(String[] args) {

		String file = args[0];
		String dump = "-d";
		if (args.length == 2) {
			if (args[1].contentEquals(dump)) {
				loadQuestions(args[0]);
				dumpQuestions();
			} else {
				System.err.print("Failed To dump, Please use format (excuatable -d   )");
			}
		} else {
			loadQuestions(args[0]);
			System.out.println("Hope your read. Its quiz Time!!");
			System.out.println("After each answer is displayed, press enter to see the next question");

			if (args.length == 2) {
				if (args[1] == dump) {
					loadQuestions(args[0]);
					dumpQuestions();
				}
			}
			double numCorrect = deliverQuiz();
			double numQuestions = numQuestions();
			double percent = (numCorrect / numQuestions) * 100;
			System.out.println("You got " + numCorrect + " out of " + numQuestions + " which is " + percent + "%");
		}
	}

//-------------------------------------------------------
	/**
	 * The vector in which questions for our quiz our stored
	 */
	static Vector<Question> questions = new Vector<Question>(10);
//-------------------------------------------------------
	/**
	 * This public int takes the total number of questions that contain errors and
	 * sends its to deliver quiz so it knows that we how many questions that have no
	 * errors.
	 */
	static int totalUnErrorQuestions = 0;

//-------------------------------------------------------
	/**
	 * Loads all questions in given txt file into vector and Validates text file
	 * before loading them to check for errors.
	 * 
	 * @param args This is the text file you want to load.
	 * @return bool This returns true is text file was loaded properly else returns
	 *         false.
	 */
	public static boolean loadQuestions(String args) {
		int lineNum = 0;
		File file = new File(args);
		try {
			Scanner fsc = new Scanner(file);
			while (fsc.hasNextLine()) {
				lineNum++;
				String line = fsc.nextLine();
				Question temp = new Questiontf();
				char letter1 = line.charAt(0);
				char letter2 = line.charAt(1);

				if (Validate.isValid(line, lineNum)) {
					totalUnErrorQuestions++;
					if (letter1 == 'S' && letter2 == 'A')
						temp = new Questionsa();
					if (letter1 == 'T' && letter2 == 'F')
						temp = new Questiontf();
					if (letter1 == 'M' && letter2 == 'C' || letter1 == 'M' && letter2 == 'A')
						temp = new Questionmc();
					String[] tokens = line.split("\\|");
					temp.setType(tokens[0]);
					temp.setLevel(tokens[1]);
					if (line.charAt(0) == 'M' && line.charAt(1) == 'C'
							|| line.charAt(0) == 'M' && line.charAt(1) == 'A') {
						String question = tokens[2] + ":" + tokens[3];
						temp.setQuestion(question);
						temp.setAnswer(tokens[4]);
					} else {
						temp.setQuestion(tokens[2]);
						temp.setAnswer(tokens[3]);
					}
					questions.add(temp);
				}
			}
			fsc.close();
		} catch (FileNotFoundException e) {
			System.err.println("Error: " + file.getAbsolutePath() + " not found.");
		}
		return true;
	}

//-------------------------------------------------------
	/**
	 * Dumps all questions and answers onto interface for a quick way to make sure
	 * it is reading your text file correctly.
	 */
	static void dumpQuestions() {
		int size = questions.size();
		for (int i = 0; i < size; i++) {
			System.out.println("----------------------------------");
			questions.get(i).showQuestion();
			System.out.print("The answer is: ");
			questions.get(i).showAnswer();

		}
	}

//-------------------------------------------------------	
	/**
	 * Delivers quiz to user. Once all questions are answered user can retake
	 * Incorrect answers or end the quiz. This can continue to happen Until all
	 * answers are correct or until user gives up and wants to end the quiz.
	 * 
	 * @return int Returns the num of correct questions answered during the quiz.
	 */
	static int deliverQuiz() {
		int correct = 0;
		int size = questions.size();
		Scanner myObj = new Scanner(System.in);
		int i = 0;
		String takeAgain = "Y";
		do {

			if (questions.get(i).correct == false) {
				System.out.print("-------------------------\n");
				questions.get(i).showQuestion();
				String userGuess = myObj.nextLine();

				if (questions.get(i).checkAnswer(userGuess)) {
					System.out.println("Correct! Good Job!");
					questions.get(i).correct = true;
					correct++;

				} else {
					System.out.print("Sorry the Answer was ");
					questions.get(i).showAnswer();
				}
			}
			i++;

			if (correct == totalUnErrorQuestions) {
				return correct;
			}
			if (i == size) {
				i = 0;
				System.out.print("Do you want to retry the one's you missed? Y/N?");
				takeAgain = myObj.nextLine();
			}
		} while (takeAgain.charAt(0) == 'Y' || takeAgain.charAt(0) == 'y');

		return correct;
	}

//-------------------------------------------------------
	/**
	 * This function returns the total amount of questions in the quiz and returns
	 * it so we can find the percentage the user got on the quiz.
	 * 
	 * @return int Returns the num of total questions in the quiz
	 */
	static int numQuestions() {
		int capacity = questions.size();
		return capacity;
	}
}

//-------------------------------------------------------
