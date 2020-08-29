using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PipeMove : MonoBehaviour
{
    public float speed; // скорость для движения труб

    void Update()
    {
        transform.Translate(-speed * Time.deltaTime, 0, 0); // движение труб
    }    
}
