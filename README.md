<!DOCTYPE html>

<h1>Program Description: BMI Calculator</h1>

<h2>Specification:</h2>

<ul>
    <li><strong>Language:</strong> C</li>
    <li><strong>Libraries Used:</strong> stdio.h, stdlib.h, bool.h, string.h</li>
    <li><strong>Additional Modules:</strong> displayCalories.h, bmi.h, login.h</li>
    <li><strong>Data Storage:</strong> User data is stored in "progress2.txt".</li>
    <li><strong>Progress Tracking:</strong> Progress data is stored in "progress.txt".</li>
    <li><strong>Maximum Users:</strong> Supports up to 100 users.</li>
</ul>

<h2>Description:</h2>

<p>
    The BMI Calculator program allows users to calculate their Body Mass Index (BMI) and track their progress. It provides a user-friendly interface with options to log in or use the program without authentication.
</p>

<h3>Main Features:</h3>

<ol>
    <li><strong>User Authentication:</strong> Users can log in with their username and password. Sample login credentials are provided.</li>
    <li><strong>BMI Calculation:</strong> Users can calculate their BMI by inputting their height and weight.</li>
    <li><strong>Caloric Needs Calculation:</strong> Provides an option to calculate caloric needs.</li>
    <li><strong>Progress Tracking:</strong> Users can view their BMI history.</li>
    <li><strong>Data Persistence:</strong> User data is stored in a text file ("progress2.txt").</li>
    <li><strong>Progress Logging:</strong> Progress data, including username, BMI, and date, is logged in "progress.txt".</li>
</ol>

<h2>Usage:</h2>

<p>
    - Upon execution, the program prompts users to log in or proceed without logging in.<br>
    - After successful login, users are presented with a menu to choose from various options.<br>
    - They can calculate their BMI, caloric needs, view BMI history, or exit the program.<br>
    - Progress is tracked and logged for future reference.
</p>

<h2>Sample User Data (Stored in "progress2.txt"):</h2>

<p>
    - User 1:<br>
    &emsp;- Username: user1<br>
    &emsp;- Password: password1<br>
    &emsp;- BMI: 191.2<br>
    &emsp;- Date: 21.01.2023<br><br>
    - User 2:<br>
    &emsp;- Username: user2<br>
    &emsp;- Password: password2<br>
    &emsp;- BMI: 37<br>
    &emsp;- Date: 12.02.2023<br>
</p>

<p><strong>Note:</strong><br>
- This is a partial code snippet. Additional functionalities may be implemented as per requirements.<br>
- Ensure correct file paths and error handling for file operations.</p>

</body>
</html>
