class Menu extends Component {

  // �R���X�g���N�^
  constructor(props) {
    super(props);
    // State��`
    this.state = {
      name: "�H�열�V��",
      book: "�m�q�t"
      count: 0
    };
    // "this"�ɃA�N�Z�X���郁�\�b�h��Bind����
    this.onClickButton = this.onClickButton.bind(this);
  }

  // �`�惁�\�b�h
  render() {
    return (
      <div className="MenuComponent">
        <h1>������Menu�R���|�[�l���g�ł���I</h1>
        ����: {this.state.name}<br/>
        ��i: {this.state.book}
        �J�E���^: {this.state.count}<br/>
        <button onClick={this.onClickButton}>PUSH</button>
      </div>
    );
  }

  // �{�^���������̏���
  onClickButton() {
    // Stete���X�V(�J�E���^�����Z)
    this.setState({
      count: this.state.count + 1
    });
  }
}

export default Menu;