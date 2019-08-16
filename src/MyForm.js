var ReactDOM = require('react-dom');
var React = require('react');

// class Form extends React.Component {
//   send() {
//     const method = "POST";
//     const body = new FormData(this.form);
//     fetch("https://httpbin.org/post", { method, body })
//       .then(res => res.json())
//       .then(data => alert(JSON.stringify(data, null, "\t")));
//   }
//   render() {
//     return (
//       <div>
//         <h1>I'm a form.</h1>
//         <form ref={el => (this.form = el)}>
//           <label>I'll be a null value:</label>
//           <input type="text" name="im-empty" />
//           <label>I'll be filled in:</label>
//           <input
//             type="text"
//             name="im-not-empty"
//             value="Im already filled in."
//           />
//           <label>I'll be an empty file:</label>
//           <input type="file" name="im-an-empty-file" />
//           <form>
//             <h1>I'm a nested form</h1>
//             <label>FormData wont even know I'm here!</label>
//             <input type="file" name="im-a-nested-empty-file" />
//           </form>
//         </form>
//         <button onClick={() => this.send()}>Send</button>
//         <p>Submit me to see what I send to the server.</p>
//       </div>
//     );
//   }
// }


class Hello extends React.Component {
  render() {
    return React.createElement('div', null, `Hello ${this.props.toWhat}`);
  }
}


var MyForm = function(props) 
{ 
  if (props.show) {
    //return React.createElement(Form, {toWhat: 'World'}, null);
    return React.createElement(Hello, {toWhat: 'World'}, null);

    // return React.createElement('div', null,
    //   'Here\'s the message from the owner: ' + props.message, 
    // );
  } 
  else {
    return null;
  }
};

module.exports = MyForm;