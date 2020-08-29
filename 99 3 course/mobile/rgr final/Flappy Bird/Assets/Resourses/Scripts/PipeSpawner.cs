using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PipeSpawner : MonoBehaviour
{
    public GameObject Pipes;        // переменная для префабов 

    void Start()
    {
        StartCoroutine(Spawner());  // включаем "Spawner" 
    }

    IEnumerator Spawner()           
    {
        while (true)                // бесконечный цикл
        {
            yield return new WaitForSeconds(2);     // ждем 2 секунды
            float rand = Random.Range(0f, 2f);     // рандомная позиция от 0 до2 
            GameObject newPipes = Instantiate(Pipes, new Vector3(2, rand, 0), Quaternion.identity);     // переносим отвественность на новый gameObject и создаем префаб
            Destroy(newPipes, 10);  // удаление нового gameObject'a через 10 секунд 
        }
    }
}
