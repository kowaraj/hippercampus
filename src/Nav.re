  
[@react.component]
let make = () => {
  <nav style=StyleNav.nav>
    <ul style=StyleNav.ul>
//      <li> <Link href="/home" name="HOME" /> </li>
      <li style=StyleNav.li> <Link href="/upload" name="UPLOAD" /> </li>
      <li style=StyleNav.li> <Link href="/meme" name="M" /> </li>
      <li style=StyleNav.li> <Link href="/meme2" name="M2" /> </li>
      <li style=StyleNav.li> <Link href="/meme3" name="M3" /> </li>
      <li style=StyleNav.li> <Link href="/dbdump" name="DB_DUMP" /> </li>
      // <li> <Link href="/tones" name="EMOTIONAL_TONES" /> </li>
    </ul>
  </nav>;
};