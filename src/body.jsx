import React, { useState } from 'react';
import './body.css';

function Body() {
  const [tasks, setTasks] = useState([1, 2]); 


  const addTask = () => {
    setTasks([...tasks, tasks.length + 1]);
  };
  const updateTask = (index, newValue) => {
  const newTasks = [...tasks];
  newTasks[index] = newValue;
  setTasks(newTasks);
};

 
  const removeTask = () => {
    setTasks(tasks.slice(0, -1)); 
  };

  return (
    <div className="container">
      <div className="task">
        Group of Tasks
      <ul>
  {tasks.map((task, index) => (
    <li key={index}>
      <input
        type="text"
        value={task}
        onChange={(e) => updateTask(index, e.target.value)}
      />
    </li>
  ))}
</ul>
        <div className="buttons">
          <button onClick={addTask}>+</button>
          <button onClick={removeTask}>-</button>
        </div>
      </div>
    
    </div>
  );
}

export default Body;
