using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;                                       // для работы с ui

public class Score : MonoBehaviour
{
    public int score;                                       // переменная для очков                                       
    public Text scoreText;                                  // переменная для текста

    void Start()
    {
        score = 0;                                          // при старте кол-во очков будет равнять 0 
    }
    void Update()
    {
        scoreText.text = score.ToString();                  // это связь очков и текста
    }

    private void OnTriggerEnter2D(Collider2D collision)     // метод для прохода через объект
    {
        if (collision.tag == "Score")                       // если птичка проходит через объект с тэгом "Score"
        {
            score++;                                        // то прибавляется одно очко (ну типо score = score + 1)
        }
    }
}
