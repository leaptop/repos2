using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
public class MY : MonoBehaviour
{

    void Update()
    {
        if (Input.GetMouseButtonDown(0))                // если жмем на кнопку мыши или экран
        {
            SceneManager.LoadScene(0); // Перезагрузка
        }
    }
}
